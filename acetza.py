import sys
from py.build import build
from py.init import init
from py.clean import clean
from py.run import run

command = sys.argv[1]

match command:
    case "build":
        compiler = sys.argv[1]
        config = sys.argv[2]
        target = sys.argv[3]
        build(compiler=compiler, config=config, target=target)
    case "run":
        compiler = sys.argv[1]
        config = sys.argv[2]
        target = sys.argv[3]
        run(compiler=compiler, config=config, target=target)
    case "init":
        compiler = sys.argv[1]
        config = sys.argv[2]
        target = sys.argv[3]
        init(compiler=compiler, config=config, target=target)
    case "clean":
        clean()
    case _:
        print("command not recognized")
