package game

import rl "github.com/gen2brain/raylib-go/raylib"
import "OlafRPG/settings"

func (p *Player) Update() {
	dt := rl.GetFrameTime()

	player.running = rl.IsKeyDown(settings.KeySprint)

	finalSpeed := player.speed
	if player.running {
		finalSpeed *= 2.0
	}

	scaledSpeed := finalSpeed * dt

	if rl.IsKeyDown(settings.KeyLeft) || rl.IsKeyDown(rl.KeyLeft) {
		p.bounds.X -= scaledSpeed
	}
	if rl.IsKeyDown(settings.KeyRight) || rl.IsKeyDown(rl.KeyRight) {
		p.bounds.X += scaledSpeed
	}
	if rl.IsKeyDown(settings.KeyDown) || rl.IsKeyDown(rl.KeyDown) {
		p.bounds.Y += scaledSpeed
	}
	if rl.IsKeyDown(settings.KeyUp) || rl.IsKeyDown(rl.KeyUp) {
		p.bounds.Y -= scaledSpeed
	}
}