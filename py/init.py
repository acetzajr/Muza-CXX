import subprocess


def init(compiler: str, config: str, target: str) -> int:
    match target.lower():
        case "muza":
            print("> target Muza")
        case _:
            print(f"> target '{target}' not recognized")
            return 1
    match compiler.lower():
        case "llvm":
            cmake_c_compiler = "clang"
            cmake_cxx_compiler = "clang++"
            print("> using 'LLVM' compilers")
            print(f"> C: {cmake_c_compiler}")
            print(f"> CXX: {cmake_cxx_compiler}")
        case "gnu":
            cmake_c_compiler = "gcc"
            cmake_cxx_compiler = "g++"
            print("> using 'GNU' compilers")
            print(f"> C: {cmake_c_compiler}")
            print(f"> CXX: {cmake_cxx_compiler}")
        case _:
            print(f"> compiler '{compiler}' not recognized")
            return 1
    match config.lower():
        case "debug":
            cmake_build_type = "Debug"
            print(
                f"> CMAKE_BUILD_TYPE -> {cmake_build_type}: Disable optimizations - include debug information"
            )
        case "release":
            cmake_build_type = "Release"
            print(
                f"> CMAKE_BUILD_TYPE -> {cmake_build_type}: Optimize for speed - exclude debug information"
            )
        case "relwithbebinfo":
            cmake_build_type = "RelWithDebInfo"
            print(
                f"> CMAKE_BUILD_TYPE -> {cmake_build_type}: Optimize for speed - include debug information"
            )
        case "minsizerel":
            cmake_build_type = "MinSizeRel"
            print(
                f"> CMAKE_BUILD_TYPE -> {cmake_build_type}: Optimize for smallest binary size - exclude debug information"
            )
        case _:
            print(f"> config '{config}' not recognized")
            return 1
    result = subprocess.run(
        [
            "cmake",
            "-S=.",
            "-B=build",
            f"-DCMAKE_BUILD_TYPE={cmake_build_type}",
            f"-DCMAKE_C_COMPILER={cmake_c_compiler}",
            f"-DCMAKE_CXX_COMPILER={cmake_cxx_compiler}",
            "-DCMAKE_EXPORT_COMPILE_COMMANDS=ON",
        ]
    )
    return result.returncode
