# -*- coding: utf-8 -*-
"""
Created on Tue Dec 14 12:40:13 2021

@author: 91908
"""

import cv2
import time
import pose_module as pm

cap = cv2.VideoCapture(r"C:\Users\91908\Downloads\AI 105.mp4")
pTime = 0
detector = pm.PoseDetector()
while True:
    success, img = cap.read()
    img = detector.findPose(img)
    lmList = detector.getPosition(img)
    print(lmList)

    cTime = time.time()
    fps = 1 / (cTime - pTime)
    pTime = cTime

    cv2.putText(img, str(int(fps)), (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 3)
    cv2.imshow("Image", img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    
cap.release()
cv2.destroyAllWindows()