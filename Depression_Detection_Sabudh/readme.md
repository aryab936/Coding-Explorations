There are 29 files in this directory. Here I provide with a brief description of what each file is all about.
1. Basic CNN-AU plots: In depression detection, Action Units are proven to be good indicators of depression, particularly AU01, AU04, AU11, AU15. A basic CNN based model with an accuracy of 82.35% was created based on the plots of the intensities of these action units in the video over time.
2. Converting mp3 to wav: This notebook deals with the use of Pydub to convert audio from mp3 into wav so that it can be processed by the OpenSmile Library.
3. Eye blink detector and duration of eye closure: This notebook uses face and eye landmarks to calculate the eye aspect ratios and caclulate blinks and duration of eye closure.
4. File listing for training: This is a simple notebook on file handling that lists down the filepaths and their associated class which is then used for custom training(using tensorflow classes because we had to create a separate data loader in order to stop RAM explosions).
5. MEL Spectrogram 80 sec: This notebook deals with the traversal of a complete directory and the creation of mel spectrograms for CNN models.
6. MEL Spectrogram Basic CNN-20sec: This notebook deals with the creation of a custom data loader and then the creation of a tensorflow model inheriting from tf.keras.Model.
7. MEL Spectrogram Basic CNN-80sec: This notebook deals with a regular straightforward model created using tensorflow.(No custom data loaders or models used)
8.  
