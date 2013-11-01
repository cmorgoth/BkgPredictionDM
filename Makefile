CXX = $(shell root-config --cxx)
LD = $(shell root-config --ld)

INC=$(shell pwd)

STDINCDIR :=-I$(INC)/include
STDLIBDIR := 

CPPFLAGS := $(shell root-config --cflags) $(STDINCDIR)
LDFLAGS := $(shell root-config --glibs) $(STDLIBDIR)

CPPFLAGS += -g

<<<<<<< HEAD
#TARGET = BkgPred
TARGET = Pred2D

#SRC = BkgPred_TT_MC_ONLY_Hybrid.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
#SRC = BkgPred_FullData_Hybrid.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
SRC = Prediction_2d.cc
=======
TARGET = BkgPred
#TARGET = Pred2D

SRC = BkgPred_TT_MC_ONLY_Hybrid.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
#SRC = BkgPred_FullData_Hybrid.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
#SRC = Prediction_2d.cc
>>>>>>> 100d60ef7a3751c470f583bc0dc808c8e8770691


OBJ = $(SRC:.cc=.o)

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(LD) $(CPPFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)
	@echo $@
	@echo $<
	@echo $^

%.o : %.cc	
	$(CXX) $(CPPFLAGS) -o $@ -c $<
	@echo $@	
	@echo $<
clean :
	rm -f *.o src/*.o $(TARGET) *~

