import * as scene from './scenes/menu';

class Game extends Phaser.Game {
    constructor() {
        const config = {
            title: "Olaf RPG",
            width: 800,
            height: 600,
            zoom: 1,
            type: Phaser.CANVAS,
            stableSort: -1,
            parent: document.getElementById("content")! ,
            canvas: document.getElementById("game")! as HTMLCanvasElement,
            scene: scene.Menu,
        };

        super(config);
    }

    update() {
        
    }

    preload() {
        
    }

    create() {
    }
}

function resizeCanvas(event) {
    var game = document.getElementById("game") as HTMLCanvasElement;
    game.width = window.innerWidth;
    game.height = window.innerHeight;
}

window.onload = () => {
    var game = new Game();
    resizeCanvas(null);
};

window.onresize = resizeCanvas;