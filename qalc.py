"""
This program is licensed under the GNU General Public License v3.0.
You may redistribute and/or modify it under the terms of the GPL-3.0.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

For details, see <https://www.gnu.org/licenses/gpl-3.0.html>
"""

import math
from sympy import sympify, simplify, N, pretty
from colorama import Fore, Style, init

# Initialize colorama
init(autoreset=True)

def evaluate_qalc_expression(expression):
    """
    Evaluate a qalc-like expression and provide intermediate and final results with colors,
    without showing redundant intermediate symbolic results.
    """
    try:
        # Parse the input expression
        sym_expr = sympify(expression, evaluate=True)
        simplified_expr = simplify(sym_expr)
        
        # Numerical evaluation
        decimal_result = N(sym_expr)

        # Format the result for pretty printing
        intermediate_steps = pretty(simplified_expr, use_unicode=True)
        decimal_result_formatted = f"{float(decimal_result):.12g}"  # Limit significant digits

        # Prepare the colored response
        return (
            f"{Fore.CYAN}  {expression} = "
            f"{Fore.YELLOW}{intermediate_steps} = "
            f"{Fore.GREEN}{decimal_result_formatted}"
        )
    except Exception as e:
        return f"{Fore.RED}Error: {e}"

def main():
    # Print the GPL 3.0 license disclaimer
    print(f"{Fore.MAGENTA}This program is licensed under the GPL 3.0 License.")
    print(f"{Fore.MAGENTA}It comes with ABSOLUTELY NO WARRANTY;")
    print(f"{Fore.MAGENTA}For details, see <https://www.gnu.org/licenses/gpl-3.0.html>\n")
    
    print(f"{Fore.CYAN}Enhanced qalc-cli in Python with Colors. Type 'exit' to quit.")
    while True:
        user_input = input(Fore.CYAN + "> ").strip()
        if user_input.lower() in {"exit", "quit"}:
            print(f"{Fore.GREEN}Goodbye!")
            break
        if not user_input:
            continue
        print(evaluate_qalc_expression(user_input))

if __name__ == "__main__":
    main()

