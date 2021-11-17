//
// Created by nils on 11/4/21.
//

#include "launcher.h"

#include <QProcess>
#include <QDebug>

Launcher::Launcher(QObject *parent) : QObject(parent) {
}


void Launcher::launch(bool offline) {
    QProcess process;
    process.setProgram("/home/nils/.lunarclient/jre/zulu16.30.15-ca-fx-jdk16.0.1-linux_x64/bin/java");
    process.setArguments({"--add-modules", "jdk.naming.dns", "--add-exports", "jdk.naming.dns/com.sun.jndi.dns=java.naming", "-Djna.boot.library.path=natives", "--add-opens", "java.base/java.io=ALL-UNNAMED", "-Xms4g", "-Xmx4g", "-Djava.library.path=natives", "-XX:-DisableAttachMechanism", "-cp", "vpatcher-prod.jar:lunar-prod-optifine.jar:lunar-libs.jar:lunar-assets-prod-1-optifine.jar:lunar-assets-prod-2-optifine.jar:lunar-assets-prod-3-optifine.jar:OptiFine.jar", "com.moonsworth.lunar.patcher.LunarMain", "--version", "1.8", "--accessToken", "0", "--assetIndex", "1.8", "--userProperties", "{}", "--gameDir", "/home/nils/.minecraft", "--texturesDir", "/home/nils/.lunarclient/textures", "--launcherVersion", "2.7.4", "--width", "854", "--height", "480"});
    process.setWorkingDirectory("/home/nils/.lunarclient/offline/1.8/");
    process.startDetached();

    emit finished();
}
