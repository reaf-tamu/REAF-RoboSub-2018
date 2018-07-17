import cv, cv2
import numpy as np

def rotateImage(image, angle):
    if hasattr(image, 'shape'):
        image_center = tuple(np.array(image.shape)/2)
        shape = image.shape
    elif hasattr(image, 'width') and hasattr(image, 'height'):
        image_center = (image.width/2, image.height/2)
        shape = np.array((image.width, image.height))
    else:
        raise Exception, 'Unable to acquire dimensions of image for type %s.' % (type(image),)
    rot_mat = cv2.getRotationMatrix2D(image_center, angle,1.0)
    result = cv2.warpAffine(image, rot_mat, shape, flags=cv2.INTER_LINEAR)
    return result

cap = cv.CaptureFromCAM(cam_index)
#cap = cv.CaptureFromFile(path)
fps = 24
width = int(cv.GetCaptureProperty(cap, cv.CV_CAP_PROP_FRAME_WIDTH))
height = int(cv.GetCaptureProperty(cap, cv.CV_CAP_PROP_FRAME_HEIGHT))

fourcc = cv.CV_FOURCC('P','I','M','1') #is a MPEG-1 codec

writer = cv.CreateVideoWriter('out.avi', fourcc, fps, (width, height), 1)
max_i = 90
for i in xrange(max_i):
    print i,max_i
    cv.GrabFrame(cap)
    frame = cv.RetrieveFrame(cap)
    frame = rotateImage(frame, 180)
    cv.WriteFrame(writer, frame)

