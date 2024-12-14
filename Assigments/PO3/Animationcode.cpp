#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

using namespace std;

class Animation : public sf::Drawable {
private:
    vector<sf::Texture> frameTextures; // Vector to store textures for each animation frame
    sf::Texture finalTexture;          // Texture for the final displayed dice face
    int currentIndex;                  // Index of the current frame in the animation
    int frameDelayMilliseconds;        // Delay per frame in milliseconds
    bool isAnimationActive;            // Flag to check if the animation is currently active
    sf::Clock animationTimer;          // Timer to track frame changes
    string imageFolder;                // Directory containing the frame images
    string filePrefix;                 // Prefix for frame image files
    sf::Sprite displaySprite;          // Sprite used to display the animation

public:
    // Constructor to initialize frame timing and load images
    Animation(int delayMs = 50) : frameDelayMilliseconds(delayMs), currentIndex(0), isAnimationActive(false), imageFolder("") {}
    Animation(string folder, string prefix, int delayMs = 50)
        : frameDelayMilliseconds(delayMs), currentIndex(0), isAnimationActive(false), imageFolder(folder), filePrefix(prefix) {}

    // Load a sequence of frames into textures
    void loadFrames(int startFrame, int endFrame, const string& customFolder = "") {
        if (!customFolder.empty()) {
            imageFolder = customFolder;
        }
        frameTextures.clear();
        for (int i = startFrame; i <= endFrame; ++i) {
            string filename = imageFolder + filePrefix + (i < 10 ? "00" + to_string(i) : "0" + to_string(i)) + ".png";
            sf::Texture texture;
            if (!texture.loadFromFile(filename)) {
                cerr << "Error loading " << filename << endl;
                continue;
            }
            frameTextures.push_back(texture);
        }
    }

    // Start playing the animation
    void play() {
        isAnimationActive = true;
        currentIndex = 0;
        animationTimer.restart();
    }

    // Update the animation frame based on the elapsed time
    void update() {
        if (!isAnimationActive) return;

        if (animationTimer.getElapsedTime().asMilliseconds() > frameDelayMilliseconds) {
            currentIndex = (currentIndex + 1) % frameTextures.size();
            if (currentIndex < frameTextures.size()) {
                displaySprite.setTexture(frameTextures[currentIndex]);
                animationTimer.restart();
            } else {
                isAnimationActive = false; // End the animation
                // Select and display a random dice face (1 to 6)
                mt19937 rng(static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count()));
                uniform_int_distribution<int> dist(1, 6);
                int diceFace = dist(rng);
                string finalFilename = imageFolder + filePrefix + (diceFace < 10 ? "0" + to_string(diceFace) : to_string(diceFace)) + ".png";
                if (!finalTexture.loadFromFile(finalFilename)) {
                    cerr << "Error loading " << finalFilename << endl;
                    return;
                }
                displaySprite.setTexture(finalTexture);
            }
        }
    }

    bool isAnimationActive() const { return isAnimationActive; }

    void setPosition(float x, float y) { displaySprite.setPosition(x, y); }
    void setScale(float x, float y) { displaySprite.setScale(x, y); }

    // Override the draw method to define custom drawing behavior
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(displaySprite, states); // Draw the sprite to the target
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "Dice Roll Animation");
    map<string, Animation> diceAnimations;

    // Initialize and configure animations
    diceAnimations["northDice"] = Animation("./images/rotated/north/", "frame_", 30);
    diceAnimations["northDice"].setPosition(100, 100);
    diceAnimations["northDice"].setScale(0.50f, 0.50f);
    diceAnimations["northDice"].loadFrames(1, 24);

    diceAnimations["southDice"] = Animation("./images/rotated/south/", "frame_", 30);
    diceAnimations["southDice"].setPosition(200, 100);
    diceAnimations["southDice"].setScale(0.50f, 0.50f);
    diceAnimations["southDice"].loadFrames(1, 24);

    diceAnimations["eastDice"] = Animation("./images/rotated/east/", "frame_", 30);
    diceAnimations["eastDice"].setPosition(100, 200);
    diceAnimations["eastDice"].setScale(0.50f, 0.50f);
    diceAnimations["eastDice"].loadFrames(1, 24);

    diceAnimations["westDice"] = Animation("./images/rotated/west/", "frame_", 30);
    diceAnimations["westDice"].setPosition(200, 200);
    diceAnimations["westDice"].setScale(0.50f, 0.50f);
    diceAnimations["westDice"].loadFrames(1, 24);

    // Main loop for handling events and rendering
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();

            // Start or restart animation on mouse click
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                for (auto& [id, animation] : diceAnimations) {
                    if (!animation.isAnimationActive()) animation.play();
                }
            }
        }

        window.clear();
        for (auto& [id, animation] : diceAnimations) {
            animation.update();
            window.draw(animation);
        }
        window.display();
    }

    return 0;
}

