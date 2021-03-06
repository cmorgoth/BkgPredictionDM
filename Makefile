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
TARGET5 = SysPlots
TARGET6 = BkgPred_MRcat_V2
TARGET7 = BkgPred_MRcat_Final
TARGET8 = Kfactor

SRC1 = Main/PrintBkgContributions.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
SRC2 = Main/BkgPred_TT_MC_ONLY_Hybrid_ScaleFactors_Systematics_MR_Categories_TTCLOSURE.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
SRC3 = Main/BkgPred_TT_MC_ONLY_Hybrid_ScaleFactors_Systematics_MR_Categories.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
SRC4 = Main/Prediction_2d.cc
SRC5 = Main/EvaluateSystematics.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
SRC6 = Main/BkgPred_Systematics_MR_Categories_BinsV2.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
SRC7 = Main/Final_Bkg_Prediction.cc src/DM_1DRatio.cc src/DM_2DRatio.cc src/DM_Base.cc
SRC8 = Main/ExtractKfactor.cc

OBJ1 = $(SRC1:.cc=.o)
OBJ2 = $(SRC2:.cc=.o)
OBJ3 = $(SRC3:.cc=.o)
OBJ4 = $(SRC4:.cc=.o)
OBJ5 = $(SRC5:.cc=.o)
OBJ6 = $(SRC6:.cc=.o)
OBJ7 = $(SRC7:.cc=.o)
OBJ8 = $(SRC8:.cc=.o)

all : $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) $(TARGET7) $(TARGET8)

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

$(TARGET5) : $(OBJ5)
	$(LD) $(CPPFLAGS) -o $(TARGET5) $(OBJ5) $(LDFLAGS)
	@echo $
	@echo $<
	@echo $^

$(TARGET6) : $(OBJ6)
	 $(LD) $(CPPFLAGS) -o $(TARGET6) $(OBJ6) $(LDFLAGS)
	@echo $
	@echo $<
	@echo $^

$(TARGET7) : $(OBJ7)
	$(LD) $(CPPFLAGS) -o $(TARGET7) $(OBJ7) $(LDFLAGS)
	@echo $
	@echo $<
	@echo $^

$(TARGET8) : $(OBJ8)
	$(LD) $(CPPFLAGS) -o $(TARGET8) $(OBJ8) $(LDFLAGS)
	@echo $
	@echo $<
	@echo $^

%.o : %.cc	
	$(CXX) $(CPPFLAGS) -o $@ -c $<
	@echo $@	
	@echo $<
clean :
	rm -f *.o src/*.o $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) $(TARGET7) $(TARGET8)*~

