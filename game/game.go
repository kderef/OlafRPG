package game

import (
	rl "github.com/gen2brain/raylib-go/raylib"
)

const (
	WindowWidth = 640
	WindowHeight = 480
)

type Game struct {
	ShouldClose bool
	flags uint32
	targetFPS int32
}

func MonitorRefreshRate() int32 {
	monitor := rl.GetCurrentMonitor()
	refresh := rl.GetMonitorRefreshRate(monitor)
	return int32(refresh)
}

func (g *Game) SetResizable(enable bool) {
	if enable {
		g.flags |= rl.FlagWindowResizable
	}
}

func (g *Game) SetRefreshRate(refresh int32) {
	g.targetFPS = refresh
}

func (g *Game) SetHighDPI(enable bool) {
	if enable {
		g.flags |= rl.FlagWindowHighdpi
	}
}

func (g *Game) Init(w, h int32, title string) {
	rl.SetConfigFlags(g.flags)

	rl.InitWindow(800, 450, "raylib [core] example - basic window")
	rl.InitAudioDevice()

	// calculate FPS
	if g.targetFPS > 0 {
		rl.SetTargetFPS(g.targetFPS)
	}
}

func (g *Game) Close() {
	rl.CloseAudioDevice()
	rl.CloseWindow()
}

// New game
func New() Game {
	return Game {
		targetFPS: 0,
	}
}