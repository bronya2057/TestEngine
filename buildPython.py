import os
import shutil
import argparse
import subprocess

parser = argparse.ArgumentParser(description="arguments for engine build")
parser.add_argument("-config", default='Debug', choices=['Release', 'Debug'])
parser.add_argument("-platform", default='x64', choices=['Win32', 'x64'])

args = parser.parse_args()

print(args)

cmakeBuildDir = "cmakeBuild" + args.config
buildDir = os.path.join(os.getcwd(), "build")
buildDir = os.path.join(buildDir, cmakeBuildDir)


def prepareCleanBuild():
    if args.clean:
        print("BUILD: Cleaning old build...")
        try:
            shutil.rmtree(buildDir)
        except:
            print("WARNING: couldn't remove directory " + buildDir)
        print("BUILD: Cleaning DONE")


def createBuildDirectory(dir_path):
    try:
        print("BUILD: Creating directory: " + dir_path)
        os.makedirs(dir_path)
    except:
        print("BUILD: folder exists. skipping")


def configure_and_build():
    if os.name == "nt":
        generator = "Visual Studio 14 2015 Win64"
    else:
        generator = "Unix Makefiles"

    cmake_args =["cmake" , "--build", ".", "--config", "Release"]

    subprocess.check_call(["cmake", "-G", generator, "../.."], cwd=buildDir)
    subprocess.check_call(cmake_args, cwd=buildDir)

createBuildDirectory(buildDir)
configure_and_build()
