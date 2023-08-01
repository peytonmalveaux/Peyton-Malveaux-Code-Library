from pytube import YouTube
import os

# Set the download directory
#download_directory = os.path.join('C:', 'Users', 'cdmal', 'OneDrive', 'mYYTSHI')

try:
    while True:
        # Get the YouTube URL input from the user
        yt_url = input("Enter the YouTube URL (or press 'Ctrl + C' to exit): ")

        if not yt_url:
            print("Exiting the program.")
            break

        my_video = YouTube(yt_url)
        stream = my_video.streams.filter(only_audio=True).first()

        filename = f"{my_video.title}.mp3"  # Format the filename using an f-string
       # stream.download(output_path='C:\\Users\\cdmal\\OneDrive\\mYYTSHI', )
        
        stream.download('C:\\Users\\cdmal\\OneDrive\\mYYTSHI',filename=filename)
        print(f"Audio from '{my_video.title}' has been downloaded as '{my_video.title}.mp3'")
except Exception as e:
    print("Error:", e)