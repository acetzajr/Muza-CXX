import sys
import time
from py.build import build as build_
from py.init import init as init_
from py.clean import clean as clean_
from py.run import run as run_


def need_some_arguments(n: int) -> bool:
    if len(sys.argv) <= n:
        print(f"> need at least {n} command line arguments")
        return True
    return False


def build() -> int:
    if need_some_arguments(4):
        return 1
    compiler = sys.argv[2]
    config = sys.argv[3]
    target = sys.argv[4]
    code = init_(compiler=compiler, config=config, target=target)
    if code != 0:
        return code
    return build_(config=config, target=target)


def run() -> int:
    if need_some_arguments(4):
        return 1
    compiler = sys.argv[2]
    config = sys.argv[3]
    target = sys.argv[4]
    code = init_(compiler=compiler, config=config, target=target)
    if code != 0:
        return code
    return build_(config=config, target=target)


def init() -> int:
    if need_some_arguments(4):
        return 1
    compiler = sys.argv[2]
    config = sys.argv[3]
    target = sys.argv[4]
    return init_(compiler=compiler, config=config, target=target)


def rebuild() -> int:
    clean_()
    print("> build cleaned")
    if need_some_arguments(4):
        return 1
    compiler = sys.argv[2]
    config = sys.argv[3]
    target = sys.argv[4]
    code = init_(compiler=compiler, config=config, target=target)
    if code != 0:
        return code
    return build_(config=config, target=target)


def main():
    need_some_arguments(1)
    command = sys.argv[1]
    match command:
        case "build":
            return build()
        case "run":
            return run()
        case "init":
            return init()
        case "clean":
            clean_()
            print("> build cleaned")
            return 0
        case "rebuild":
            return rebuild()
        case _:
            print("> command not recognized")
            return 1


if __name__ == "__main__":
    print("Acetza")
    format_spec = "{:,.3f}"
    start = time.time()
    code = main()
    elapsed = time.time() - start
    print(f"{format_spec.format(elapsed * 1_000)} ms")
    sys.exit(code)
