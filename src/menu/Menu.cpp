/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include <sstream>

#include "greentop/menu/Menu.h"

namespace greentop {
namespace menu {

Menu::Menu() : root(this) {
}

void Menu::fromJson(const std::string& json) {
    Json::Value jsonValue;
    Json::Reader reader;
    reader.parse(json.c_str(), jsonValue);
    fromJson(jsonValue);
}

void Menu::fromJson(const Json::Value& json) {
    children.clear();
    parents.clear();
    root.fromJson(json);
    addParent(&root);

}

const std::string Menu::makeNodeId(const Node& node) const {
    std::ostringstream ss;
    ss << static_cast<int>(node.getType());

    return ss.str() + "-" + node.getId();
}

void Menu::addChild(const Node& parentNode, const Node& childNode) {

    std::string parentNodeId = makeNodeId(parentNode);
    std::string childNodeId = makeNodeId(childNode);

    children[parentNodeId].push_back(childNode);

    addParent(&children[parentNodeId].back());

}

void Menu::addParent(Node* parentNode) {

    for (auto it = parentNode->getChildren().begin(); it != parentNode->getChildren().end(); ++it) {
        std::string childId = makeNodeId(*it);
        parents[childId] = parentNode;
    }

    /* for (unsigned i = 0; i < parentNode->getChildren().size(); ++i) {
        std::string childId = makeNodeId(parentNode->getChildren()[i]);
        parents[childId] = parentNode;
    } */
}

void Menu::removeChildren(const Node& parentNode) {
    children[makeNodeId(parentNode)].clear();
}

const Node& Menu::getParent(const Node& childNode) const {
    return *parents.at(makeNodeId(childNode));
}

bool Menu::hasParent(const Node& childNode) const {
    return parents.find(makeNodeId(childNode)) != parents.end();
}

const std::list<Node>& Menu::getChildren(const Node& node) const {
    return children.at(makeNodeId(node));
}

const Node& Menu::getRootNode() const {
    return root;
}

}
}
