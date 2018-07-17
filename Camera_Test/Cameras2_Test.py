import numpy as np
import cv2

cap1 = cv2.VideoCapture(0)
cap2 = cv2.VideoCapture(1)
#cap3 = cv2.VideoCapture(2)

while(True):
    # Capture frame-by-frame
    ret1, frame1 = cap1.read()
    ret2, frame2 = cap2.read()
    #ret3, frame3 = cap3.read()
    
    print (frame1.shape)
    (h,w) = frame1.shape[:2]
    center = (w / 2, h / 2)
    M = cv2.getRotationMatrix2D(center,10, 1.0)
    rotated = cv2.warpAffine(frame1, M, (w, h))
    cv2.imshow("rotated", rotated)

    # Our operations on the frame come here
    gray = cv2.cvtColor(frame1, cv2.COLOR_BGR2GRAY)

    # Display the resulting frame
    cv2.imshow('frame1',frame1)
    cv2.imshow('frame2',frame2)
    #cv2.imshow('frame3',frame3)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()