MAIN = main.go
OUT = bin/OlafRPG
DEBUG = -gcflags '-N -l'
RELEASE = -ldflags -H=windowsgui
DEBUG_FILE = debug/debug.go

ifeq ($(OS), Windows_NT)
	OUT := $(OUT).exe
endif

debug:
	echo package debug; > $(DEBUG_FILE)
	echo const Debug = true; >> $(DEBUG_FILE)
	go build -o $(OUT) $(DEBUG)

release:
	echo package debug; > $(DEBUG_FILE)
	echo const Debug = false; >> $(DEBUG_FILE)
	go build -o $(OUT) $(RELEASE)

run: $(OUT)
	$(OUT)

.PHONY: debug release run