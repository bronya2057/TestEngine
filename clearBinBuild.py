import shutil
import os

currentDir = os.getcwd()
buildDir = os.path.join(currentDir, "build")
binDir = os.path.join(currentDir, "bin")

#shutil.rmtree(buildDir)
#shutil.rmtree(binDir)

def remove_dir_contents(dir_path):
    for root, dirs, files in os.walk(dir_path):
        for f in files:
            os.unlink(os.path.join(root, f))
        for d in dirs:
            shutil.rmtree(os.path.join(root, d))

remove_dir_contents(buildDir)
remove_dir_contents(binDir)

