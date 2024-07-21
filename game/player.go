package game

import rl "github.com/gen2brain/raylib-go/raylib"

// Draw(), Update() in `draw.go`, `update.go`

type Player struct {
	speed   float32
	running bool
	bounds  rl.Rectangle
	camera  rl.Camera2D
}

var player = PlayerInit()

func PlayerInit() Player {
	bounds := rl.Rectangle{
		X:      50.0,
		Y:      40.0,
		Width:  50.0,
		Height: 50.0,
	}
	camera := rl.Camera2D{
		Rotation: 0.0,
		Zoom:     0.0,
		Offset:   rl.Vector2{X: 0, Y: 0},
		Target:   rl.Vector2{X: 20, Y: 20},
	}
	return Player {
		speed: 100.0,
		running: false,
		camera: camera,
		bounds: bounds,
	}
}
