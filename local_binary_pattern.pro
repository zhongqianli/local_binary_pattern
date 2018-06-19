TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


# opencv_win begin
OPENCV_VER = 340
COMPILER = vs2015
PLATFORM = x86
OPENCV_DIR = E:/0-myWorkSpace/0-3rdparty/opencv$$OPENCV_VER
OPENCV_LIB_DIR = $$OPENCV_DIR/$$COMPILER/$$PLATFORM/lib

message($$OPENCV_DIR)

INCLUDEPATH += $$OPENCV_DIR/include
INCLUDEPATH += $$OPENCV_DIR/include/opencv
INCLUDEPATH += $$OPENCV_DIR/include/opencv2

CONFIG(debug, debug|release){
    message(debug mode)

    DESTDIR = $$PWD/bin-debug

    if(equals(COMPILER, "vs2015")){

        message("compiler is" $$COMPILER)
    }


}else{
    message(release mode)

    DESTDIR = $$PWD/bin

    if(equals(COMPILER, "vs2015")){
        message("compiler is" $$COMPILER)

        LIBS += $$OPENCV_LIB_DIR/opencv_calib3d"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_core"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_dnn"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_features2d"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_flann"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_highgui"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_imgcodecs"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_imgproc"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_ml"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_objdetect"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_photo"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_shape"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_stitching"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_superres"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_ts"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_video"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_videoio"$$OPENCV_VER".lib
        LIBS += $$OPENCV_LIB_DIR/opencv_videostab"$$OPENCV_VER".lib
    }

    if(equals(COMPILER, "mingw530")){
        message("compiler is" $$COMPILER)
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_calib3d"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_core"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_dnn"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_features2d"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_flann"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_highgui"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_imgcodecs"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_imgproc"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_ml"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_objdetect"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_photo"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_shape"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_stitching"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_superres"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_ts"$$OPENCV_VER".a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_video"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_videoio"$$OPENCV_VER".dll.a
        LIBS += -L $$OPENCV_LIB_DIR/libopencv_videostab"$$OPENCV_VER".dll.a
    }

}

# opencv_win end

SOURCES += main.cpp \
    local_binary_pattern.cpp

HEADERS += \
    local_binary_pattern.h

