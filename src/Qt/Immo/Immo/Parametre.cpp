#include "Parametre.h"

Parametre::Parametre()
{
    QDomDocument doc( "test" );
    QFile file( "/home/isirat/Bureau/test.xml" );

    if( !file.open( QIODevice::ReadOnly ) )
      return ;
    if( !doc.setContent( &file ) )
    {
      file.close();
      return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    if( root.tagName() != "ParametreConnexion" )
    {
         return;
    }
    QDomNode n = root.firstChild();
    while( !n.isNull() )
    {
      QDomElement e = n.toElement();
        if( !e.isNull() )
        {
            if( e.tagName() == "TypeConnection" )
            {
                typeConnection = e.text();
                n = n.nextSibling();
            }

            else if( e.tagName() == "Host" )
            {
                host = e.text();
                n = n.nextSibling();
            }
            else if ( e.tagName() == "DataBaseName" )
            {
                dataBaseName = e.text();
                n = n.nextSibling();
            }
            else if ( e.tagName() == "User" )
            {
                user = e.text();
                n = n.nextSibling();
            }
            else if ( e.tagName() == "Password" )
            {
                password = e.text();
                n = n.nextSibling();
            }
         }
    }
}

QString Parametre::getTypeConnection()
{
    return typeConnection;
}

QString Parametre::getHost()
{
    return host;
}

QString Parametre::getDataBaseName()
{
    return dataBaseName;
}

QString Parametre::getUser()
{
    return user;
}

QString Parametre::getPassword()
{
    return password;
}
