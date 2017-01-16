##############################################################################
# IA32_PGF:		Intel Pentium with Linux using Portland Group compiler
##############################################################################
F90_SER = pgf90
F90_OMP = pgf90
F90_MPI = mpif90
FLAGS_OPT = -fast
FLAGS_MSC = -Mfixed
FLAGS90_MSC = -Mfree
FLAGS_DYN =
FLAGS_SER =
FLAGS_OMP = -mp
FLAGS_MPI = -tp barcelona-64
NETCDFROOT =
ifneq ($(NETCDFROOT),)
  INCS_SER = -I$(NETCDFROOT)/include
  INCS_OMP = -I$(NETCDFROOT)/include
  INCS_MPI = -I$(NETCDFROOT)/include
  LIBS_SER = -L$(NETCDFROOT)/lib -lnetcdf -lnetcdff
  LIBS_OMP = -L$(NETCDFROOT)/lib -lnetcdf -lnetcdff
  LIBS_MPI = -L$(NETCDFROOT)/lib -lnetcdf -lnetcdff
  NCF_OBJS = nctablemd.o agioncmd.o swn_outnc.o
else
  INCS_SER =
  INCS_OMP =
  INCS_MPI =
  LIBS_SER =
  LIBS_OMP =
  LIBS_MPI =
  NCF_OBJS =
endif
O_DIR = ../work/odir4/
OUT = -o 
EXTO = o
MAKE = make
RM = rm -f
ifneq ($(NETCDFROOT),)
  swch = -unix -impi -netcdf
else
  swch = -unix -impi
endif
