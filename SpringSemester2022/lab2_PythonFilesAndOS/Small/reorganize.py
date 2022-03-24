import argparse
import sys
import os
from datetime import datetime
import shutil

def createParser():
    parser = argparse.ArgumentParser()
    parser.add_argument('-src', '--source', type=str, default=os.getcwd())
    parser.add_argument('-d', '--days', type=int, default=0)
    parser.add_argument('-s', '--size', type=int)
 
    return parser

def daysCheck(namespace):
    dir = os.path.join(namespace.source, "Archive")
    for filename in os.listdir(namespace.source):
        if (os.path.isdir(namespace.source + '/' + filename)):
            continue
        with open(filename, 'r') as file:
            fileCreated = datetime.fromtimestamp(os.path.getmtime("{}/{}".format(namespace.source, file.name)))
            if (datetime.now() - fileCreated).days >= namespace.days:
                if not (os.path.exists(dir)):
                    os.mkdir(dir)
                    print("Archive was created! " + dir)
                print(file.name)
                shutil.copyfile("{}/{}".format(namespace.source, file.name), "{}/{}".format(dir, file.name))

def sizeCheck(namespace):
    dir = os.path.join(namespace.source, "Small")
    for filename in os.listdir(namespace.source):
        if (os.path.isdir(namespace.source + '/' + filename)):
            continue
        with open(filename, 'r') as file:
            fileSize = os.path.getsize("{}/{}".format(namespace.source, file.name))
            if (fileSize <= namespace.size):
                if not (os.path.exists(dir)):
                    os.mkdir(dir)
                    print("Small was created! " + dir)
                print(file.name)
                shutil.copyfile("{}/{}".format(namespace.source, file.name), "{}/{}".format(dir, file.name))
                
            

if __name__ == "__main__":
    parser = createParser()
    namespace = parser.parse_args(sys.argv[1:])
    print("Source: ", namespace.source)
    print("Days: ", namespace.days)
    print("Size: ", namespace.size)
    daysCheck(namespace)
    print()
    sizeCheck(namespace)