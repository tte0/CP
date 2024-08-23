"""
    freopen("correct_output.txt","w",stdout);freopen("testcase.in","r",stdin);
    freopen("user_output.txt","w",stdout);freopen("testcase.in","r",stdin);

"""

import subprocess
from termcolor import colored
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
index = 0
report_interval = 1
debug_logs_enabled = True
while True:
    try:
        # Generate a random test case
        if debug_logs_enabled:
            debug("Generating test case...")
        subprocess.run(["./testcasegenerator"])
        testcase_file = "testcase.in"

        # Run the correct program with input redirection
        if debug_logs_enabled:
            debug(f"Running correct program with input redirection...")
        correct_output_file = "correct_output.txt"
        user_output_file = "user_output.txt"
        correct_proc = subprocess.Popen(["./correct < " + testcase_file + " > " + correct_output_file], shell=True, stdout=subprocess.PIPE, universal_newlines=True)
        correct_proc.communicate()
        if debug_logs_enabled:
            debug(f"Correct program output: {correct_output_file}")

        # Check the results
        if correct_proc.returncode != 0:
            fail_output(index, f"Correct program failed with return code {correct_proc.returncode}.")
            exit(0)

        # Run the user program with input redirection
        if debug_logs_enabled:
            debug(f"Running user program with input redirection...")
        user_proc = subprocess.Popen(["./user < " + testcase_file + " > " + user_output_file], shell=True, stdout=subprocess.PIPE, universal_newlines=True)
        user_proc.communicate()
        if debug_logs_enabled:
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

        # Compare outputs with case-insensitive comparison for "yes" or "no" lines
        for correct_line, user_line in zip(correct_output, user_output):
            if correct_line.lower() in ["yes", "no"] and user_line.lower() in ["yes", "no"]:
                if correct_line.lower() != user_line.lower():
                    wa_output(index, f"Test case failed.")
                    exit(0)
            elif correct_line != user_line:
                wa_output(index, f"Test case failed.")
                exit(0)

        # If all lines match, print PASS
        if index % report_interval == 0:
            pass_output(index)

        # Update report interval
        if index == 20:
            report_interval = 2
        elif index == 50:
            report_interval = 5
        elif index == 100:
            report_interval = 10

        # Disable debug logs after the first test case
        if index == 0:
            debug_logs_enabled = False

        index += 1
    except Exception as e:
        fail_output(index, f"Error: {e}")
        debug(f"Exception details: {traceback.format_exc()}")
        exit(0)

"""
    freopen("correct_output.txt","w",stdout);freopen("testcase.in","r",stdin);
    freopen("user_output.txt","w",stdout);freopen("testcase.in","r",stdin);

"""