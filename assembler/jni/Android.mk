LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_CFLAGS := -Wall -Wno-error -O -fPIE -pie
LOCAL_LDFLAGS += -pie -fPIE

LOCAL_SHARED_LIBRARIES := \
    libbase \
    libcutils \
    liblog \
    libpng \
    libutils \

LOCAL_LDLIBS    := -llog

LOCAL_SRC_FILES:= test.cpp

LOCAL_MODULE:= test

LOCAL_MODULE_PATH := $(TARGET_OUT_OPTIONAL_EXECUTABLES)

include $(BUILD_EXECUTABLE)
