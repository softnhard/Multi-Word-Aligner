/*************************************************************************
 * MWA - A Multi word alignerc
 * Copyright (C) 2012-2014  S.Mohammad M. Ziabary <mehran.m@aut.ac.ir>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *************************************************************************/
/**
 @author S.Mohammad M. Ziabary <mehran.m@aut.ac.ir>
 */

#ifndef HUMAN_H
#define HUMAN_H

#include "Engine/intfExternalDictionary.hpp"
#include "Engine/intfExternalStemmer.hpp"

class InteractiveDicAndStemmer : public intfExternalDictionary, public intfExternalStemmer
{
public:
    static inline InteractiveDicAndStemmer* instance(){
        return Instance ? Instance : (Instance = new InteractiveDicAndStemmer);
    }

    QStringList lookup(const QString &_word);
    QString     getStem(const QString &_word, bool _reverseDir);

private:

private:
    InteractiveDicAndStemmer():intfExternalDictionary("in", "Interactive"), intfExternalStemmer("in", "Interactive"){}
    static InteractiveDicAndStemmer* Instance;
};

#endif // HUMAN_H
