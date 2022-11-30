#include <stdio.h>
#include <iostream>
#include <cstdlib>

#include "GameFramework/DebugTools/Public/TJADebugWindows.h"

#include <string>

using namespace std;

void TJADebugWindows::InitImGui()
{
    for(int i = 0; rand() % 20 + 0; i++)
    {
        TJAMap* TmpMap = new TJAMap();
        TmpMap->CreateRandomData();
        MapList.push_back(TmpMap);
    }
}
struct TJATreeNode
{
    const char* Name;
    const char* Desc;
    TJAMap* TJAMap;
    
    static void DisplayNode(const TJATreeNode* node)
    {
        int flags = ImGuiTableFlags_BordersV | ImGuiTableFlags_BordersOuterH | ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_NoBordersInBody;
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        bool MasterSongDataTreeNode = ImGui::TreeNodeEx(node->TJAMap->SongTitle.c_str(), ImGuiTreeNodeFlags_SpanFullWidth);
        ImGui::TableNextColumn();
        if(ImGui::Button("Play Song"))
        {
            cout << "print" << endl;
        }
        
        if(MasterSongDataTreeNode)
        {
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            if(ImGui::TreeNodeEx("Song MetaData", ImGuiTreeNodeFlags_SpanFullWidth))
            {
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                
                if (ImGui::BeginTable("song_data", 2, flags))
                {
                    ImGui::TableSetupColumn("Data", ImGuiTableColumnFlags_NoHide);
                    ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_WidthFixed);
                    ImGui::TableHeadersRow();
                    
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Song Name");
                    ImGui::TableNextColumn();
                    ImGui::Text(node->TJAMap->SongTitle.c_str());

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Song Subtitle");
                    ImGui::TableNextColumn();
                    ImGui::Text(node->TJAMap->Subtitle.c_str());

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Wave File");
                    ImGui::TableNextColumn();
                    ImGui::Text(node->TJAMap->AudioFile.c_str());

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("BPM");
                    ImGui::TableNextColumn();
                    ImGui::Text(std::to_string(node->TJAMap->BaseSongBPM).c_str());

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("OFFSET");
                    ImGui::TableNextColumn();
                    ImGui::Text(std::to_string(node->TJAMap->SongOffset).c_str());

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("OFFSET");
                    ImGui::TableNextColumn();
                    ImGui::Text(std::to_string(node->TJAMap->SongOffset).c_str());

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("DEMOSTART");
                    ImGui::TableNextColumn();
                    ImGui::Text(std::to_string(node->TJAMap->DemoStart).c_str());

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("GENRE");
                    ImGui::TableNextColumn();
                    ImGui::Text(node->TJAMap->Genre.c_str());

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("SCOREMODE");
                    ImGui::TableNextColumn();
                    ImGui::Text(std::to_string(node->TJAMap->ScoreMode).c_str());

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("SONGVOL");
                    ImGui::TableNextColumn();
                    ImGui::Text(std::to_string(node->TJAMap->SongVolume).c_str());

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("SEVOL");
                    ImGui::TableNextColumn();
                    ImGui::Text(std::to_string(node->TJAMap->SeVolume).c_str());
                    
                    ImGui::EndTable();
                }
                ImGui::TreePop();
            }
            
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            for(auto& map : node->TJAMap->TJACourses)
            {
                if(ImGui::TreeNodeEx(TJAPARSER::TaikoDifficultyToString(map->Difficulty).c_str(), ImGuiTreeNodeFlags_SpanFullWidth))
                {
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    if(ImGui::BeginTable("course_metadata", 2, flags))
                    {
                        ImGui::TableSetupColumn("Data", ImGuiTableColumnFlags_NoHide);
                        ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_WidthFixed);
                        ImGui::TableHeadersRow();

                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        ImGui::Text("Course Diff");
                        ImGui::TableNextColumn();
                        ImGui::Text(TJAPARSER::TaikoDifficultyToString(map->Difficulty).c_str());

                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        ImGui::Text("Level");
                        ImGui::TableNextColumn();
                        ImGui::Text(std::to_string(map->CourseLevel).c_str());

                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        ImGui::Text("BALLOON");
                        ImGui::TableNextColumn();
                        ImGui::Text(std::to_string(map->CourseBaloonLevel).c_str());

                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        ImGui::Text("SCOREINIT");
                        ImGui::TableNextColumn();
                        ImGui::Text(std::to_string(map->CourseScoreInit).c_str());

                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        ImGui::Text("SCOREDIFF");
                        ImGui::TableNextColumn();
                        ImGui::Text(std::to_string(map->CourseScoreDiff).c_str());
                        
                        ImGui::EndTable();
                    }
                    
                    if (ImGui::BeginTable("course_data", 1, flags))
                    {
                        ImGui::TableSetupColumn("Data", ImGuiTableColumnFlags_NoHide);
                        ImGui::TableHeadersRow();
                        
                        for(auto& CourseData : map->CourseData)
                        {
                            ImGui::TableNextRow();
                            ImGui::TableNextColumn();
                            ImGui::Text(CourseData.c_str());
                        }
                        
                        ImGui::EndTable();
                    }
                    ImGui::TreePop();
                }
                
            }
            ImGui::TreePop();
            
        }
        
    }
};
void TJADebugWindows::RenderImGui()
{
    ImGui::SetNextWindowSize(ImVec2(800, 800), ImGuiCond_FirstUseEver);
    ImGui::Begin("Debug Windows");
    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[0]);
    static ImGuiTableFlags flags = ImGuiTableFlags_BordersV | ImGuiTableFlags_BordersOuterH | ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_NoBordersInBody;
    if (ImGui::TreeNode("Song Data Test"))
    {
        if (ImGui::BeginTable("3ways", 2, flags))
        {
            ImGui::TableSetupColumn("Parsed TJA", ImGuiTableColumnFlags_NoHide);
            ImGui::TableSetupColumn("Debug", ImGuiTableColumnFlags_WidthFixed);
            ImGui::TableHeadersRow();
            list<TJATreeNode*> NodeList;
            for (std::list<TJAMap*>::iterator it = MapList.begin(); it != MapList.end(); ++it){
                TJATreeNode* TmpNode = new TJATreeNode();
                TmpNode->TJAMap = *it;
                NodeList.push_back(TmpNode);
            }
            
            for (std::list<TJATreeNode*>::iterator it = NodeList.begin(); it != NodeList.end(); ++it){
                TJATreeNode::DisplayNode(*it);
            }
            ImGui::EndTable();
        }
        ImGui::TreePop();
    }
    ImGui::PopFont();
    ImGui::End();
}



