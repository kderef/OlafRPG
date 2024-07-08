#!/usr/bin/env python3

import sys
from os import system, chdir as cd, getcwd
args = sys.argv[1:]

FILE = "manage.py" # __file__

#####################################################

def cmd(cmd: str) -> int:
    print(cmd)
    return system(cmd)

def build(release: bool):
    cmd(f"make {'release' if release else 'debug'}")

def init():
    cmd("git submodule update --init --recursive")
    cd("ext/raylib/src")
    cmd("make")
    cd("../../../")
    print("\nInit Completed.")

#####################################################

def stop(msg: any):
    print(f"[EXITING...] {msg}")
    exit(0)

def usage():
    print(f"{FILE} [init] [build] [build-release]")

def parse_arg(arg: str):
    arg = arg.strip().lower()
    funcs = {
        "init": init,
        "build": lambda: build(release=False),
        "build-release": lambda: build(release=True)
    }
    if arg in funcs:
        return funcs[arg]
    else:
        print(f"invalid command: '{arg}'")
        usage()
        stop(f"UNKNOWN COMMAND")       

def main():
    if len(args) < 1:
        usage()
        stop("No argument provided.")

    steps = []
    for arg in args:
        f = parse_arg(arg)
        steps.append(f)

    for step in steps:
        step()

if __name__ == "__main__":
    main()