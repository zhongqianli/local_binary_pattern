TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

# win32
win32{

OPENCV_DIR = E:\0-myWorkSpace\0-3rdparty\opencv320\vs2010
message($$OPENCV_DIR)

INCLUDEPATH +=  $$OPENCV_DIR\include\
            $$OPENCV_DIR\include\opencv\
            $$OPENCV_DIR\include\opencv2\

CONFIG(debug, debug|release){
    message(debug mode)

    DESTDIR = $$PWD/bin

    LIBS += $$OPENCV_DIR\x86\lib\opencv_calib3d320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_core320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_features2d320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_flann320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_highgui320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_imgproc320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_imgcodecs320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_ml320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_objdetect320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_photo320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_shape320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_stitching320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_superres320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_ts320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_video320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_videoio320d.lib\
            $$OPENCV_DIR\x86\lib\opencv_videostab320d.lib\

}else{
    message(release mode)
    DESTDIR = $$PWD/bin

    LIBS += $$OPENCV_DIR\x86\lib\opencv_calib3d320.lib\
            $$OPENCV_DIR\x86\lib\opencv_core320.lib\
            $$OPENCV_DIR\x86\lib\opencv_features2d320.lib\
            $$OPENCV_DIR\x86\lib\opencv_flann320.lib\
            $$OPENCV_DIR\x86\lib\opencv_highgui320.lib\
            $$OPENCV_DIR\x86\lib\opencv_imgproc320.lib\
            $$OPENCV_DIR\x86\lib\opencv_imgcodecs320.lib\
            $$OPENCV_DIR\x86\lib\opencv_ml320.lib\
            $$OPENCV_DIR\x86\lib\opencv_objdetect320.lib\
            $$OPENCV_DIR\x86\lib\opencv_photo320.lib\
            $$OPENCV_DIR\x86\lib\opencv_shape320.lib\
            $$OPENCV_DIR\x86\lib\opencv_stitching320.lib\
            $$OPENCV_DIR\x86\lib\opencv_superres320.lib\
            $$OPENCV_DIR\x86\lib\opencv_ts320.lib\
            $$OPENCV_DIR\x86\lib\opencv_video320.lib\
            $$OPENCV_DIR\x86\lib\opencv_videoio320.lib\
            $$OPENCV_DIR\x86\lib\opencv_videostab320.lib\
} # config

} # win32


SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

