import pathlib, os, shlex, subprocess

ROOT = pathlib.Path(__file__).parent.resolve()
GENERATOR = "Visual Studio 16"
BIN_OUT = ROOT / "bin"

if "Visual Studio" in GENERATOR:
	GENERATOR_OUT = ROOT / "_project"

	if not GENERATOR_OUT.exists():
		GENERATOR_OUT.mkdir()

	if not BIN_OUT.exists():
		BIN_OUT.mkdir()

	os.chdir(GENERATOR_OUT)


GENERATE_COMMAND_ARGS = shlex.split(f"cmake -G {shlex.quote(GENERATOR)} {ROOT.as_posix()}")

CMAKE_PROC = subprocess.run(GENERATE_COMMAND_ARGS)

if CMAKE_PROC.returncode != 0:
	exit(CMAKE_PROC.returncode)