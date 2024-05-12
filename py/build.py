import subprocess


def build(config: str, target: str) -> int:
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
