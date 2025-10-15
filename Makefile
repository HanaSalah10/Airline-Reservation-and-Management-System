# Cross-Platform Makefile for Airline Reservation and Management System
# Works on Linux, Windows (MinGW/MSYS2), and macOS

# Detect operating system
ifeq ($(OS),Windows_NT)
    # Windows (MinGW/MSYS2)
    DETECTED_OS := Windows
    TARGET = main.exe
    RM = del /Q
    RMDIR = rmdir /S /Q
    MKDIR = mkdir
    PATHSEP = \\
    EXECUTABLE = main.exe
    RUN_CMD = main.exe
else
    DETECTED_OS := $(shell uname -s)
    TARGET = main
    RM = rm -f
    RMDIR = rm -rf
    MKDIR = mkdir -p
    PATHSEP = /
    EXECUTABLE = main
    RUN_CMD = ./main
endif

# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./include
SRCDIR = src
INCDIR = include
OBJDIR = obj

# Platform-specific flags
ifeq ($(DETECTED_OS),Windows)
    CXXFLAGS += -static-libgcc -static-libstdc++
endif

ifeq ($(DETECTED_OS),Linux)
    CXXFLAGS += -pthread
endif

# Source files
SOURCES = main.cpp $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

# Create object directory
$(OBJDIR):
	$(MKDIR) $(OBJDIR)
	$(MKDIR) $(OBJDIR)$(PATHSEP)$(SRCDIR)

# Default target
all: $(TARGET)

# Build the main executable
$(TARGET): $(OBJDIR) $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build complete for $(DETECTED_OS)"

# Compile source files to object files
$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
ifeq ($(DETECTED_OS),Windows)
	@if exist $(TARGET) $(RM) $(TARGET)
	@if exist $(OBJDIR) $(RMDIR) $(OBJDIR) 2>NUL || echo "Clean complete"
else
	$(RM) $(TARGET)
	$(RMDIR) $(OBJDIR)
endif
	@echo "Clean complete"

# Run the program
run: $(TARGET)
	$(RUN_CMD)

# Compile and run in one command
build-run: clean $(TARGET) run

# Debug build
debug: CXXFLAGS += -g -DDEBUG -O0
debug: clean $(TARGET)
	@echo "Debug build complete for $(DETECTED_OS)"

# Release build (optimized)
release: CXXFLAGS += -O2 -DNDEBUG
release: clean $(TARGET)
	@echo "Release build complete for $(DETECTED_OS)"

# Check for compilation errors only
check:
	$(CXX) $(CXXFLAGS) -fsyntax-only $(SOURCES)
	@echo "Syntax check complete"

# Install (copy to system path) - Unix-like systems only
install: $(TARGET)
ifneq ($(DETECTED_OS),Windows)
	@echo "Installing to /usr/local/bin (requires sudo)"
	sudo cp $(TARGET) /usr/local/bin/
else
	@echo "Install target not supported on Windows. Copy $(TARGET) to desired location manually."
endif

# Show system information
info:
	@echo "Detected OS: $(DETECTED_OS)"
	@echo "Compiler: $(CXX)"
	@echo "Flags: $(CXXFLAGS)"
	@echo "Target: $(TARGET)"
	@echo "Run command: $(RUN_CMD)"

# Help target
help:
	@echo "Cross-Platform Makefile for Airline Reservation System"
	@echo "Supports: Linux, Windows (MinGW/MSYS2), macOS"
	@echo ""
	@echo "Available targets:"
	@echo "  all       - Build the project (default)"
	@echo "  clean     - Remove build artifacts"
	@echo "  run       - Run the program"
	@echo "  build-run - Clean, build, and run in one command"
	@echo "  debug     - Build with debug symbols and no optimization"
	@echo "  release   - Build optimized release version"
	@echo "  check     - Check for compilation errors only"
	@echo "  install   - Install to system path (Unix-like only)"
	@echo "  info      - Show system and build information"
	@echo "  help      - Show this help message"
	@echo ""
	@echo "Platform-specific features:"
	@echo "  Windows   - Static linking, .exe extension"
	@echo "  Linux     - pthread support"
	@echo "  macOS     - Standard Unix behavior"

# Dependencies (optional - for better incremental builds)
$(OBJDIR)/main.o: main.cpp $(wildcard $(INCDIR)/*.hpp)
$(OBJDIR)/$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.hpp

# Phony targets
.PHONY: all clean run build-run debug release check install info help

# Print variables for debugging the Makefile itself
print-%:
	@echo $* = $($*)
