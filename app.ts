class SimpleGame {
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
        };

        this.game = new Phaser.Game(config)
    }

    game: Phaser.Game;

    preload() {
        
    }

    create() {
    }

}
window.onload = () => {
    var game = new SimpleGame();

    window.onresize(null);
};

window.onresize = (event) => {
    var game = document.getElementById("game") as HTMLCanvasElement;
    game.width = window.innerWidth;
    game.height = window.innerHeight;
};