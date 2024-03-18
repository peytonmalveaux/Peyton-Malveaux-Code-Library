import os
import re

directory_path = '/users/cdmal/OneDrive/Desktop/'
print(f"directory_path: {directory_path}")
what = input("What file pattern to search for? ")
found = False

if os.path.isdir(directory_path):
    fileList = os.listdir(directory_path)
    files_to_delete = []

    for fileName in fileList:
        if re.search(what, fileName):
            files_to_delete.append(fileName)
            found = True

    if found:
        print("Matching files found:")
        for file in files_to_delete:
            print(file)

        confirmation = input("Do you want to delete these files? (yes/no): ").lower()

        if confirmation == 'yes':
            for file in files_to_delete:
                filePath = os.path.join(directory_path, file)
                os.remove(filePath)
                print(f"Deleted: {file}")
            print("Deletion completed.")
        else:
            print("Deletion canceled.")
    else:
        print("No matching files found")
else:
    print("Directory doesn't exist")
