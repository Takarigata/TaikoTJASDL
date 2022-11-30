#include "../Public/GameSFML.h"

#include <algorithm>
#include "imgui-SFML.h"
#include "GameFramework/DebugTools/Public/TJADebugWindows.h"

GameSFML::GameSFML()
{}

GameSFML::~GameSFML()
{}

void GameSFML::init(const char* title, int width, int height, bool fullscreen)
{
    int flag = 4;
    if(fullscreen)
    {
        flag = 8;
    }
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), title, flag);
    m_window->setFramerateLimit(144);
    ImGui::SFML::Init(*m_window, false);
    InitImGuiFont();
    InitDebugTools();
    m_deltaClock = new sf::Clock();
    
    font = new sf::Font();
    if(font)
    {
        font->loadFromFile("DFPKanteiryu-XB.ttf");
    }

    auto text = new sf::Text();
    auto renderstate = new sf::RenderStates();
    text->setFont(*font);
    text->setString(L"Taiko no 太鼓の達人, アニメ, ひらがな");
    text->setCharacterSize(24);
    text->setStyle(sf::Text::Bold);
    text->setFillColor(sf::Color::Red);

    shape = new sf::CircleShape(20.f);
    ObjectsToDraw.insert(std::pair<sf::Drawable*, sf::RenderStates*>(text, renderstate));
    ObjectsToDraw.insert(std::pair<sf::Drawable*, sf::RenderStates*>(shape, renderstate));
    
    TJAPARSER::TJAParserLib* ParserLib = new TJAPARSER::TJAParserLib();
    ParserLib->ParseTJAFile("C:\\DEV\\PARADOX.tja");
    if(m_window)
    {
        isRunning = true;
    }
}

void GameSFML::InitImGuiFont()
{
    ImGuiIO& IO = ImGui::GetIO();
    IO.Fonts->Clear();
    IO.Fonts->AddFontFromFileTTF("DFPKanteiryu-XB.ttf", 8.f, NULL, IO.Fonts->GetGlyphRangesJapanese());

    ImGui::SFML::UpdateFontTexture();
}

void GameSFML::InitDebugTools()
{
    InstancedTJADebugWindows = new TJADebugWindows();
    InstancedTJADebugWindows->InitImGui();
}

void GameSFML::update()
{
    cnt++;
}

void GameSFML::render()
{
    m_window->clear();
    std::vector<sf::Drawable*> key;
    std::vector<sf::RenderStates*> value;
    for(std::map<sf::Drawable*, sf::RenderStates*>::iterator it = ObjectsToDraw.begin(); it != ObjectsToDraw.end(); ++it) {
        key.push_back(it->first);
        value.push_back(it->second);
    }
    for(auto& ObjectToDraw : key)
    {
        m_window->draw(*ObjectToDraw, *ObjectsToDraw[ObjectToDraw]);
    }
    
    ImGui::SFML::Update(*m_window, m_deltaClock->restart());

    InstancedTJADebugWindows->RenderImGui();
    
    //ImGui::ShowDemoWindow();
    
    ImGui::SFML::Render(*m_window);
    m_window->display();
}

void GameSFML::handleEvents()
{
    sf::Event event;
    if(m_window->pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(*m_window, event);
        if(event.type == sf::Event::Closed)
        {
            isRunning = false;
        }
    }
    
}

void GameSFML::clean()
{
    ImGui::SFML::Shutdown();
    m_window->close();
}

bool GameSFML::running()
{
    return isRunning;
}








