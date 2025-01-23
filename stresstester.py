import os
import subprocess
from termcolor import colored
import traceback

testcase_code  = "testcasegenerator.cpp"
correct_code   = "correct.cpp"
user_code      = "user.cpp"

testcase_input = "testcase.txt"
correct_output = "correct.txt"
user_output    = "user.txt"

def debug(msg):
    print(colored(msg, 'grey'))

def pass_output(index):
    print(f"Testcase {index}: [{colored('AC', 'green')}]")

def fail_output(index, msg):
    print(f"Testcase {index}: [{colored('RTE', 'yellow')}] {msg}")

def wa_output(index, msg):
    print(f"Testcase {index}: [{colored('WA', 'red')}] {msg}")

index = 0
report_interval = 1
debug_logs_enabled = True


os.system("touch "+ testcase_input)
os.system("touch "+ correct_output)
os.system("touch "+ user_output)

debug("Compiling programs...")
os.system("g++ -o correct correct.cpp")
os.system("g++ -o user user.cpp")
os.system("g++ -o testcasegenerator testcasegenerator.cpp")

while True:
    try:
        if debug_logs_enabled:
            debug("Generating test case...")
        os.system("./testcasegenerator > " + testcase_input)


        if debug_logs_enabled:
            debug(f"Running correct.cpp...")
        correct_returncode = os.system("cat " + testcase_input + " | ./correct  > " + correct_output)
        if correct_returncode != 0:
            fail_output(index, f"correct.cpp return code {correct_returncode}.")
            exit(0)


        if debug_logs_enabled:
            debug(f"Running correct.cpp...")
        user_returncode = os.system("cat " + testcase_input + " | ./user  > " + user_output)
        if user_returncode != 0:
            fail_output(index, f"user.cpp return code {user_returncode}.")
            exit(0)


        with open(correct_output, "r") as f_correct:
            __correct_output = f_correct.readlines()
            __correct_output = [line.strip() for line in __correct_output if line.strip()]
        with open(user_output, "r") as f_user:
            __user_output = f_user.readlines()
            __user_output = [line.strip() for line in __user_output if line.strip()]

        for correct_line, user_line in zip(__correct_output, __user_output):
            if correct_line.lower() in ["yes", "no"] and user_line.lower() in ["yes", "no"]:
                if correct_line.lower() != user_line.lower():
                    wa_output(index, f"Test case failed.")
                    exit(0)
            elif correct_line != user_line:
                wa_output(index, f"Test case failed.")
                exit(0)


        if index % report_interval == 0:
            pass_output(index)

        if index == 20:
            report_interval = 2
        elif index == 50:
            report_interval = 5
        elif index == 100:
            report_interval = 10

        if index == 0:
            debug_logs_enabled = False

        index += 1
    except Exception as e:
        fail_output(index, f"Error: {e}")
        debug(f"Exception details: {traceback.format_exc()}")
        exit(0)