#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstdint>
#include <array>
#include "text.hpp"
#include "settingsButton.hpp"
#include "container.hpp"
#include "closeImg.hpp"
#include "clockIcon.hpp"
#include "arrowUp.hpp"
#include "arrowDown.hpp"
#include "libdigitalcontent/libdigitalcontent.cpp"
#include <cstdio>
#include <string>

int main() {
    uid_t _uid = getuid();
    if (_uid != 0) {
        printf("This program only run a root\n");
        exit(6);
    }
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 500), "Digital Contentment", sf::Style::Titlebar | sf::Style::Close);

    FILE *file = fopen("NotoSans-VariableFont_wdth,wght.ttf", "rb");
    if (file == NULL) {
        printf("[ERROR]: Failed to load font file\n");
        exit(2);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    std::vector<char> fontBuffer(fileSize);
    fread(&fontBuffer[0], 1, fileSize, file);
    fclose(file);

    sf::Font font;
    if (!font.loadFromMemory(&fontBuffer[0], fontBuffer.size())) {
        exit(1);
    }

    sf::Color backgroundColor(64, 71, 82);
    sf::Text usageText;
    int Uptime = getUptime();
    usageText.setString(std::to_string(Uptime));
    usageText.setCharacterSize(45);
    usageText.setStyle(sf::Text::Regular);
    usageText.setFont(font);
    usageText.setFillColor(sf::Color::White);
    usageText.setPosition(80,60);

    sf::Text healthText;
    healthText.setString("Technology offers several benefits, but it is important to use it\nwith moderation. By finding a balance between the digital and offline world,\nwe can enjoy the benefits of technology without compromising\nour health and well-being.\n \nConsequences of Digital Addiction: Mental Health: Anxiety, depression,\nlow self-esteem, sleep problems, social isolation. Physical Health: Eye fatigue,\nback pain, posture problems, obesity. Relationships: Communication difficulties,\nfamily conflicts, social isolation. Work and Studies: Drop in productivity,\nabsenteeism, difficulty concentrating.");
    healthText.setCharacterSize(17);
    healthText.setStyle(sf::Text::Regular);
    healthText.setFont(font);
    healthText.setFillColor(sf::Color::White);
    healthText.setPosition(80,190);

    sf::RectangleShape setingsContainer(sf::Vector2f(250,400));
    setingsContainer.setPosition(270,50);
    setingsContainer.setFillColor(sf::Color(255, 255, 255, 0));

    sf::RectangleShape shadowContainerOne(sf::Vector2f(270, 500));
    shadowContainerOne.setFillColor(sf::Color(0,0,0,0));
    sf::RectangleShape shadowContainerTwo(sf::Vector2f(250, 50));
    shadowContainerTwo.setPosition(270,0);
    shadowContainerTwo.setFillColor(sf::Color(0,0,0,0));
    sf::RectangleShape shadowContainerTree(sf::Vector2f(250, 50));
    shadowContainerTree.setPosition(270,450);
    shadowContainerTree.setFillColor(sf::Color(0,0,0,0));
    sf::RectangleShape shadowContainerFour(sf::Vector2f(400, 500));
    shadowContainerFour.setPosition(520,0);
    shadowContainerFour.setFillColor(sf::Color(0,0,0,0));

    sf::Image contianerImage;
    contianerImage.loadFromMemory(containerData.data(), containerData.size());
    sf::Texture containerTexture;
    containerTexture.loadFromImage(contianerImage);
    sf::Sprite containerSprite;
    containerSprite.setPosition(sf::Vector2f(50, 150));
    containerSprite.setTexture(containerTexture);

    sf::Color transparent = containerSprite.getColor();
    transparent.a = 0;

    sf::Image arrowupImage;
    arrowupImage.loadFromMemory(arrowupData.data(), arrowupData.size());
    sf::Texture arrowupTexture;
    arrowupTexture.loadFromImage(arrowupImage);
    sf::Sprite arrowupSprite;
    arrowupSprite.setTexture(arrowupTexture);
    arrowupSprite.setPosition(520,250);
    arrowupSprite.setRotation(90);
    arrowupSprite.setColor(transparent);

    sf::Image arrowdownImage;
    arrowdownImage.loadFromMemory(arrowdownData.data(), arrowdownData.size());
    sf::Texture arrowdownTexture;
    arrowdownTexture.loadFromImage(arrowdownImage);
    sf::Sprite arrowdownSprite;
    arrowdownSprite.setTexture(arrowdownTexture);
    arrowdownSprite.setPosition(360,250);
    arrowdownSprite.setRotation(90);
    arrowdownSprite.setColor(transparent);

    sf::Text containerText;
    containerText.setCharacterSize(19);
    containerText.setString("Usage Settings");
    containerText.setStyle(sf::Text::Regular);
    containerText.setFont(font);
    containerText.setFillColor(transparent);
    containerText.setPosition(280,60);

    sf::Text configText;
    configText.setCharacterSize(19);
    configText.setString("Set Your Usage Limit");
    configText.setStyle(sf::Text::Regular);
    configText.setFont(font);
    configText.setFillColor(transparent);
    configText.setPosition(300,375);

    int numberHours = 0;
    char numberStr[3] = "";
    sprintf(numberStr,"%d", numberHours);
    sf::Text textNumber;
    textNumber.setString(numberStr);
    textNumber.setCharacterSize(50);
    textNumber.setStyle(sf::Text::Regular);
    textNumber.setFont(font);
    textNumber.setPosition(385,260);
    textNumber.setFillColor(transparent);

    sf::Image clockImg;
    clockImg.loadFromMemory(clockImgData.data(), clockImgData.size());
    sf::Texture clockTexture;
    clockTexture.loadFromImage(clockImg);
    sf::Sprite clockSprite;
    clockSprite.setTexture(clockTexture);
    clockSprite.setPosition(340,105);
    clockSprite.setColor(transparent);

    sf::Image settingsButton;
    settingsButton.loadFromMemory(settingsButtonData.data(), settingsButtonData.size());
    sf::Texture settingsTexture;
    settingsTexture.loadFromImage(settingsButton);
    sf::Sprite settingsSprite;
    settingsSprite.setPosition(660,55);
    settingsSprite.setTexture(settingsTexture);

    sf::Image closeButton;
    closeButton.loadFromMemory(closeImgData.data(), closeImgData.size());
    sf::Texture closeTexture;
    closeTexture.loadFromImage(closeButton);
    sf::Sprite closeSprite;
    closeSprite.setTexture(closeTexture);
    closeSprite.setScale(0.08,0.08);
    closeSprite.setPosition(490,60);
    closeSprite.setColor(transparent);

    bool buttonSettingsListener = true;
    bool buttonCloseListener = false;

    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed){
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f clickPosition(event.mouseButton.x, event.mouseButton.y);
                if (settingsSprite.getGlobalBounds().contains(clickPosition) && buttonSettingsListener == true) {
                    shadowContainerOne.setFillColor(sf::Color(0,0,0,150));
                    shadowContainerTwo.setFillColor(sf::Color(0,0,0,150));
                    shadowContainerTree.setFillColor(sf::Color(0,0,0,150));
                    shadowContainerFour.setFillColor(sf::Color(0,0,0,150));
                    setingsContainer.setFillColor(sf::Color(76, 84, 97));
                    buttonSettingsListener = false;
                    buttonCloseListener = true;
                    transparent.a = 255;
                    closeSprite.setColor(transparent);
                    clockSprite.setColor(transparent);
                    arrowdownSprite.setColor(transparent);
                    arrowupSprite.setColor(transparent);
                    containerText.setFillColor(sf::Color::White);
                    configText.setFillColor(sf::Color::White);
                    textNumber.setFillColor(sf::Color::White);
                    printf("Open clicked\n");
                }

                if (closeSprite.getGlobalBounds().contains(clickPosition) && buttonCloseListener == true) {
                    setingsContainer.setFillColor(sf::Color(255, 255, 255, 0));
                    buttonSettingsListener = true;
                    buttonCloseListener = false;
                    transparent.a = 0;
                    closeSprite.setColor(transparent);
                    clockSprite.setColor(transparent);
                    arrowdownSprite.setColor(transparent);
                    arrowupSprite.setColor(transparent);
                    containerText.setFillColor(transparent);
                    shadowContainerOne.setFillColor(transparent);
                    shadowContainerTwo.setFillColor(transparent);
                    shadowContainerTree.setFillColor(transparent);
                    shadowContainerFour.setFillColor(transparent);
                    configText.setFillColor(transparent);
                    textNumber.setFillColor(transparent);
                    setTime(numberHours);
		    system("systemctl daemon-reload && systemctl start libdigitalcontent.service");
                    printf("Close clicked\n");
                }

                if(arrowdownSprite.getGlobalBounds().contains(clickPosition) && buttonCloseListener == true){
                    if (numberHours != 0) {
                        numberHours--;
                    }
                    if (numberHours < 10) {
                        textNumber.setPosition(385,260);
                    }
                    sprintf(numberStr,"%d", numberHours);
                    textNumber.setString(numberStr);
                    printf("down clicked\n");
                }

                if(arrowupSprite.getGlobalBounds().contains(clickPosition) && buttonCloseListener == true){
                    if (numberHours < 24) {
                        numberHours++;
                    }
                    if (numberHours == 10) {
                        textNumber.setPosition(365,260);
                    }
                    sprintf(numberStr,"%d", numberHours);
                    textNumber.setString(numberStr);
                    printf("up clicked\n");
                }

            }

        }

        window.clear(backgroundColor);
        window.draw(containerSprite);
        window.draw(healthText);
        window.draw(usageText);
        window.draw(settingsSprite);
        window.draw(setingsContainer);
        window.draw(closeSprite);
        window.draw(clockSprite);
        window.draw(containerText);
        window.draw(configText);
        window.draw(arrowupSprite);
        window.draw(arrowdownSprite);
        window.draw(textNumber);
        window.draw(shadowContainerOne);
        window.draw(shadowContainerTwo);
        window.draw(shadowContainerTree);
        window.draw(shadowContainerFour);
        window.display();
    }

    return EXIT_SUCCESS;
}
