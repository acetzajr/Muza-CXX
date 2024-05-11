import subprocess


def run(target=str) -> int:
    match target.lower():
        case "muza":
            target = "Muza"
        case _:
            print(f"> target '{target}' not recognized")
            return 1
    return subprocess.run([f"./build/{target}"]).returncode
