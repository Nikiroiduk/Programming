import argparse
import sys
import os
import subprocess
from xmlrpc.client import MAXINT

def createParser():
    parser = argparse.ArgumentParser()
    parser.add_argument('-s', '--source', type=str)
    parser.add_argument('-d', '--destination', type=str)
    parser.add_argument('-c', '--count', type=int, default=MAXINT)
    parser.add_argument('-f', '--frame', type=int, default=10)
    parser.add_argument('-l', '--log', type=int, default=0)
    parser.add_argument('-e', '--extended',type=int, default=0)
 
    return parser

if __name__ == "__main__":
    parser = createParser()
    namespace = parser.parse_args(sys.argv[1:])

    ffmpeg = (os.getcwd() + "\\ffmpeg.exe").replace("\\", "/")

    files = []
    i = 0
    for filename in os.listdir(namespace.source):
        if (i >= namespace.count):
            break
        i += 1
        if (namespace.log == 1):
            print(filename)
        commands = [
            ffmpeg,
            "-ss",
            "0",
            "-i",
            "{}/{}".format(namespace.source, filename),
            "-t",
            "{}".format(namespace.frame),
            "{}/Cut{}.mp3".format(namespace.source, filename[0:filename.index(".")])
        ]
        files.append("{}/Cut{}.mp3".format(namespace.source, filename[0:filename.index(".")]))
        if (namespace.log == 1):
            print(commands)
        if subprocess.run(commands).returncode == 0:
            if (namespace.log == 1):
                print ("FFmpeg Script Ran Successfully")
        else:
            print ("There was an error running your FFmpeg script")

    if not (os.path.exists(namespace.destination)):
        os.mkdir(namespace.destination)
        if (namespace.log == 1):
            print("Dirrectory was created! " + namespace.destination)

    commands = [
        ffmpeg,
        "-i",
        "concat:{}".format("|".join(files)),
        "-acodec",
        "copy",
        "{}/{}".format(namespace.destination,"result.mp3")
    ]

    if (namespace.log == 1):
        print(commands)
    if subprocess.run(commands).returncode == 0:
        if (namespace.log == 1):
            print ("FFmpeg Script Ran Successfully")
    else:
        print ("There was an error running your FFmpeg script")

    for file in files:
        os.remove(file)
