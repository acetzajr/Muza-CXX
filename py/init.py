import subprocess


def check_in_options(tag: str, options: list[str], value: str):
    for option in options:
        if option == value:
            return value
    print(f"> {tag} '{value}' not recognized")
    print("> valid options are:")
    for option in options:
        print(f"    * {option}")
    return None


def init(compiler: str, config: str, target: str) -> int:
    if check_in_options(tag="target", options=["Muza"], value=target) is None:
        return 1
    result = check_in_options(tag="compiler", options=["GNU", "LLVM"], value=compiler)
    if result is None:
        return 1
    match result:
        case "LLVM":
            cmake_c_compiler = "clang"
            cmake_cxx_compiler = "clang++"
            print("> using 'LLVM' compilers")
            print(f"> C: {cmake_c_compiler}")
            print(f"> CXX: {cmake_cxx_compiler}")
        case "GNU":
            cmake_c_compiler = "gcc"
            cmake_cxx_compiler = "g++"
            print("> using 'GNU' compilers")
            print(f"> C: {cmake_c_compiler}")
            print(f"> CXX: {cmake_cxx_compiler}")
    result = check_in_options(
        tag="configuration",
        options=["Debug", "Release", "RelWithDebInfo", "MinSizeRel"],
        value=config,
    )
    if result is None:
        return 1
    match result:
        case "Debug":
            print(
                "> CMAKE_BUILD_TYPE -> Debug: Disable optimizations - include debug information"
            )
        case "Release":
            print(
                "> CMAKE_BUILD_TYPE -> Release: Optimize for speed - exclude debug information"
            )
        case "RelWithDebInfo":
            print(
                "> CMAKE_BUILD_TYPE -> RelWithDebInfo: Optimize for speed - include debug information"
            )
        case "MinSizeRel":
            print(
                "> CMAKE_BUILD_TYPE -> MinSizeRel: Optimize for smallest binary size - exclude debug information"
            )
    args = [
        "cmake",
        "-S=.",
        "-B=build",
        f"-DCMAKE_BUILD_TYPE={config}",
        f"-DCMAKE_C_COMPILER={cmake_c_compiler}",
        f"-DCMAKE_CXX_COMPILER={cmake_cxx_compiler}",
        "-DCMAKE_EXPORT_COMPILE_COMMANDS=ON",
        f"-DACETZA_COMPILER={compiler}",
    ]
    return subprocess.run(args).returncode
