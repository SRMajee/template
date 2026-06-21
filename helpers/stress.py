import subprocess
import sys
import os

# --- IMPORT YOUR GENERATORS ---
from gen_utils import *  # --- CONFIGURATION ---

FILE_A = "solution.cpp"  # Your Optimized Code
FILE_B = "brute.cpp"  # The Brute Force Code
# ---------------------


def compile_cpp(file_path):
    exe_name = file_path.split(".")[0]
    if sys.platform == "win32":
        exe_name += ".exe"
    print(f"Compiling {file_path}...")
    try:
        subprocess.run(
            ["g++", "-std=c++17", "-O2", file_path, "-o", exe_name], check=True
        )
    except subprocess.CalledProcessError:
        print(f"Compilation failed for {file_path}")
        sys.exit(1)
    return f"./{exe_name}" if sys.platform != "win32" else exe_name


def run_exe(exe_path, input_str):
    try:
        res = subprocess.run(
            [exe_path], input=input_str, capture_output=True, text=True
        )
        return res.stdout.strip()
    except Exception as e:
        return str(e)


# --- DEFINE TEST CASE HERE ---
def generate_test_case():
    # Example for Blackslex problem
    n = gen_int(1, 5)  # Keep N small for brute force
    x = gen_int(1, 20)
    y = gen_int(1, 20)

    s = gen_binary_string(n)
    p = gen_array(n, 1, 10)

    # Format output
    out = f"1\n{n} {x} {y}\n{s}\n" + " ".join(map(str, p)) + "\n"
    return out


# -----------------------------


def main():
    if not os.path.exists(FILE_A) or not os.path.exists(FILE_B):
        print(f"Error: Ensure both {FILE_A} and {FILE_B} exist.")
        return

    exe_a = compile_cpp(FILE_A)
    exe_b = compile_cpp(FILE_B)

    test_idx = 0
    while True:
        test_idx += 1
        inp = generate_test_case()

        out_a = run_exe(exe_a, inp)
        out_b = run_exe(exe_b, inp)

        if out_a != out_b:
            print(f"\n[FAILED] Test Case #{test_idx}")
            print("--- Input ---")
            print(inp.strip())
            print("\n--- Output A (Yours) ---")
            print(out_a)
            print("\n--- Output B (Correct) ---")
            print(out_b)
            break

        print(f"Passed {test_idx} tests...", end="\r")


if __name__ == "__main__":
    main()
