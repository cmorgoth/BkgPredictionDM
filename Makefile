CXX = $(shell root-config --cxx)
LD = $(shell root-config --ld)

INC=$(shell pwd)

STDINCDIR :=-I$(INC)/include
STDLIBDIR := 

CPPFLAGS := $(shell root-config --cflags) $(STDINCDIR)
LDFLAGS := $(shell root-config --glibs) $(STDLIBDIR)

CPPFLAGS += -g

TARGET1 = PrintYields
TARGET2 = BkgPred_ttClosure_Cat
TARGET3 = BkgPred_Cat
TARGET4 = Pred2D

SRC1 = Main/PrintBkgContributions.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc

SRC2 = Main/BkgPred_TT_MC_ONLY_Hybrid_ScaleFactors_Systematics_MR_Categories_TTCLOSURE.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
SRC3 = Main/BkgPred_TT_MC_ONLY_Hybrid_ScaleFactors_Systematics_MR_Categories.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
#SRC = BkgPred_TT_MC_ONLY_Hybrid_ScaleFactors_Systematics.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
#SRC = BkgPred_TT_MC_ONLY_Hybrid.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
#SRC = BkgPred_TT_MC_ONLY_Hybrid_ScaleFactors.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
#SRC = BkgPred_TT_MC_ONLY.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
SRC4 = Main/Prediction_2d.cc


OBJ1 = $(SRC1:.cc=.o)
OBJ2 = $(SRC2:.cc=.o)
OBJ3 = $(SRC3:.cc=.o)
OBJ4 = $(SRC4:.cc=.o)

all : $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)

$(TARGET1) : $(OBJ1)
	$(LD) $(CPPFLAGS) -o $(TARGET1) $(OBJ1) $(LDFLAGS)
	@echo $@
	@echo $<
	@echo $^

$(TARGET2) : $(OBJ2)
	$(LD) $(CPPFLAGS) -o $(TARGET2) $(OBJ2) $(LDFLAGS)
	@echo $@
	@echo $<
	@echo $^

$(TARGET3) : $(OBJ3)
	$(LD) $(CPPFLAGS) -o $(TARGET3) $(OBJ3) $(LDFLAGS)
	@echo $@
	@echo $<
	@echo $^

$(TARGET4) : $(OBJ4)
	$(LD) $(CPPFLAGS) -o $(TARGET4) $(OBJ4) $(LDFLAGS)
	@echo $@
	@echo $<
	@echo $^

%.o : %.cc	
	$(CXX) $(CPPFLAGS) -o $@ -c $<
	@echo $@	
	@echo $<
clean :
	rm -f *.o src/*.o $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)*~

