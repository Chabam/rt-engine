import pathlib, os, shlex, subprocess

ROOT = pathlib.Path(__file__).parent.resolve()

GENERATOR_OUT = ROOT / "_project"
BIN_OUT = ROOT / "bin"

if not GENERATOR_OUT.exists():
	GENERATOR_OUT.mkdir()

if not BIN_OUT.exists():
	BIN_OUT.mkdir()

os.chdir(GENERATOR_OUT)

GENERATOR = shlex.quote("Visual Studio 16 2019")
TOOLSET = "x64"

GENERATE_COMMAND_ARGS = shlex.split(f"cmake -G {GENERATOR} -A {TOOLSET} {ROOT.as_posix()}")

CMAKE_PROC = subprocess.run(GENERATE_COMMAND_ARGS)

if CMAKE_PROC.returncode != 0:
	exit(CMAKE_PROC.returncode)