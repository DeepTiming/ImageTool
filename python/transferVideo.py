import cv2
import os

fps = 1
size=(500,500)

fourcc = cv2.VideoWriter_fourcc(*'XVID')
videoWriter = cv2.VideoWriter('inception.avi',fourcc,fps,size)

for root, dirs, files in os.walk('/Users/rainjoe/Desktop/dede'):    
    for filename in files:
        frame = cv2.imread(os.path.join(root, filename))
        frame = cv2.resize(frame,size)
        videoWriter.write(frame)

videoWriter.release()
