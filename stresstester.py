"""
    freopen("correct_output.txt","w",stdout);freopen("testcase.in","r",stdin);
    freopen("user_output.txt","w",stdout);freopen("testcase.in","r",stdin);

"""

import subprocess
import time
import random
import sys
import re
from termcolor import colored
import os
import traceback

# Compile the C++ programs
subprocess.run(["g++", "-o", "correct", "correct.cpp"])
subprocess.run(["g++", "-o", "user", "user.cpp"])
subprocess.run(["g++", "-o", "testcasegenerator", "testcasegenerator.cpp"])

# Set the time limit
time_limit = 5

# Define color-coded output functions
def debug(msg):
    print(colored(msg, 'grey'))

def pass_output(index):
    print(f"Testcase {index}: [{colored('PASS', 'green')}]")

def fail_output(index, msg):
    print(f"Testcase {index}: [{colored('FAIL', 'red')}] {msg}")

def wa_output(index, msg):
    print(f"Testcase {index}: [{colored('WA', 'yellow')}] {msg}")

# Run the test case generator and the correct and user programs indefinitely
index = 1
while True:
    try:
        # Generate a random test case
        debug("Generating test case...")
        subprocess.run(["./testcasegenerator"])
        testcase_file = "testcase.in"

        # Run the correct program with input redirection
        debug(f"Running correct program with input redirection...")
        correct_output_file = "correct_output.txt"
        user_output_file = "user_output.txt"
        correct_proc = subprocess.Popen(["./correct < " + testcase_file + " > " + correct_output_file], shell=True, stdout=subprocess.PIPE, universal_newlines=True)
        correct_proc.communicate()
        debug(f"Correct program output: {correct_output_file}")

        # Check the results
        if correct_proc.returncode != 0:
            fail_output(index, f"Correct program failed with return code {correct_proc.returncode}.")
            exit(0)

        # Run the user program with input redirection
        debug(f"Running user program with input redirection...")
        user_proc = subprocess.Popen(["./user < " + testcase_file + " > " + user_output_file], shell=True, stdout=subprocess.PIPE, universal_newlines=True)
        user_proc.communicate()
        debug(f"User program output: {user_output_file}")

        # Check the results
        with open(correct_output_file, "r") as f_correct:
            correct_output = f_correct.readlines()
            correct_output = [line.strip() for line in correct_output if line.strip()]
        with open(user_output_file, "r") as f_user:
            user_output = f_user.readlines()
            user_output = [line.strip() for line in user_output if line.strip()]

        if user_proc.returncode != 0:
            fail_output(index, f"User program failed with return code {user_proc.returncode}.")
            exit(0)
        elif correct_output != user_output:
            wa_output(index, f"Test case failed.")
            exit(0)
            
        else:
            pass_output(index)

        index += 1
    except Exception as e:
        fail_output(index, f"Error: {e}")
        debug(f"Exception details: {traceback.format_exc()}")
        exit(0)
