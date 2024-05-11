import subprocess


def build(config: str, target: str) -> int:
    match target.lower():
        case "muza":
            print("> target Muza")
            target = "Muza"
        case _:
            print(f"> target '{target}' not recognized")
            return 1
    match config.lower():
        case "debug":
            config = "Debug"
        case "release":
            config = "Release"
        case "relwithbebinfo":
            config = "RelWithDebInfo"
        case "minsizerel":
            config = "MinSizeRel"
        case _:
            print(f"> config '{config}' not recognized")
            return 1
    return subprocess.run(
        [
            "cmake",
            "--build",
            "build",
            "--config",
            config,
            "--target",
            target,
            "--parallel",
            "16",
        ]
    ).returncode
