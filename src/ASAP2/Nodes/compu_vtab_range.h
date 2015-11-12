// HEXplorer is an Asap and HEX file editor
// Copyright (C) 2011  <Christophe Hoel>
//
// This file is part of HEXplorer.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// please contact the author at : christophe.hoel@gmail.com

#ifndef COMPU_VTAB_RANGE_H
#define COMPU_VTAB_RANGE_H

#include "node.h"
#include "basefactory.h"
#include "Items/default_value.h"


class COMPU_VTAB_RANGE : public Node
{
    public:
        COMPU_VTAB_RANGE(Node *parentNode);
        ~COMPU_VTAB_RANGE();
        static Factory<Node, COMPU_VTAB_RANGE> nodeFactory;

        QMap<std::string, std::string> *getParameters();
        std::string pixmap();
        QString getValue(int i);
        QStringList getValueList();
        int getPos(QString str);
        char* getPar(std::string str);

    private:
        // Fix parameters
        QList<TokenTyp> *typePar;
        QList<std::string> *namePar;
        QList<char*> parameters;
        QMap<int, std::string> valuePairs;
        QList<int> listKeyPairs;
        QList<std::string> listValuePairs;

        // Opt parameters
        QMap<std::string, FactoryPlant<Node> *>  *factoryOptNode;
        QMap<std::string, FactoryPlant<Item> *>  *factoryOptItem;

        void parsePairs();
        void parseFixPar(QList<TokenTyp> *typePar);
        TokenTyp parseOptPar();
};

#endif // COMPU_VTAB_RANGE_H
