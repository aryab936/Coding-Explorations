#Depression Detection Using AI
##There are 28 code files in this directory. Here I provide with a brief description of what each file is all about.
1. Basic CNN-AU plots: In depression detection, Action Units are proven to be good indicators of depression, particularly AU01, AU04, AU11, AU15. A basic CNN based model with an accuracy of 82.35% was created based on the plots of the intensities of these action units in the video over time.
2. Converting mp3 to wav: This notebook deals with the use of Pydub to convert audio from mp3 into wav so that it can be processed by the OpenSmile Library.
3. Depression Audio Extraction: This notebook deals with the extraction of audio from a video that has audio embedded in it.
4. Disvoice-Audio_Features: The code here deals with the use of a library called Disvoice which can be used to extract glottal and phonation features. The notebook traverses a file directory and extracts Glottal and phonation features from the audio files present.
5. Eye blink detector and duration of eye closure: This notebook uses face and eye landmarks to calculate the eye aspect ratios and caclulate blinks and duration of eye closure.
6. File listing for training: This is a simple notebook on file handling that lists down the filepaths and their associated class which is then used for custom training(using tensorflow classes because we had to create a separate data loader in order to stop RAM explosions).
7. MEL Spectrogram 80 sec: This notebook deals with the traversal of a complete directory and the creation of mel spectrograms for CNN models.
8. MEL Spectrogram Basic CNN-20sec: This notebook deals with the creation of a custom data loader and then the creation of a tensorflow model inheriting from tf.keras.Model.
9. MEL Spectrogram Basic CNN-80sec: This notebook deals with a regular straightforward model created using tensorflow.(No custom data loaders or models used)
10. MFCC Basic CNN: This notebook has the same basic CNN architecture but works with MFCCs instead of MEL spectrograms.
11. MFCC(Sliced Audio): This notebook creates MFCC Plots for audio files that were sliced using the overlapping window approach.
12. MFCC: This notebook creates MFCC plots for audio files that were not sliced.
13. OpenFace_AUs: This notebook uses the OpenFace library and uses it to create CSV files containg detailed feature sets of each and every frame of all the video files. Some visualisation of the AUs has also been done to understand how the outputs look.
14. OpenSmile Features Basic CNN: This notebook uses the plots of the various low level descriptors generated using OpenSmile and uses a basic CNN architecture for a model that works on predicting whether the person has depression or not. 
15. OpenSmile Plotting: This notebook plots a specific low level descriptor extracted by OpenSmile and creates the data for the CNN model.
16. OpenSmile and Crepe for audio and prosody: This notebook is mostly exploratory and just reflects some exploration that I had done with OpenSmile and Crepe.
17. Opensmile_Feature_Plots_1: This notebook generates plots similar to the OpenSmile Plotting notebook.
18. Shutil move_files: This notebook deals with the use of shutil in Python to move files between directories. This is mostly exploratory in nature.
19. Silence_Detection using Pydub: This notebook deals with the detection of silence in an audio file using Pydub. Since the volume of the audio is low the volume had to be adjusted before good results were obtained. Hence the notebook has some tweaks on those lines too.
20. Slicing-70 sec and 10 overlap: This notebook deals with the slicing of extracted audio from video files into chunks with 70 seconds of original content and 10 seconds of overlapping content with the previous audio chunk.
21. Speaker Diarisation-Trial: This notebook outlines my exploration with some possible libraries which have been shown to work relatively better at speaker diarisation.
22. Waveform Generation: This notebook looks at using the Librosa library to visualise the waveform of the audio file.
23. Web Cam face detection: A Google Colab version of using webcam along with OpenCV to detect faces in a live video feed.
24. eyeball: This python file tracks the movement of the eyeball of the person using OpenCV and dlib. This is useful for the depression peoject because eyeball movement can be considered to be an indirect indicator of restlessness, anxiety, depression ,etc.
25. headpose: This python file tracks the movement of the head and its tilt(in degrees) against both the x and y axes on a frame by fram basis.
26. laughter-detection: This notebook uses a pre-trained laughter detection model to detect whether the audio slice has any instances of laughter within it.
27. pose_detection: This python file does pose detection using the pose_module.py file. It gives a real-time analysis of how the person is moving within the video which can have important clues on whether the person is depressed or not.
28. pose_module: This module uses OpenCV and mediapipe to track the posture of the person.
