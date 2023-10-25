import QtQuick 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Qt QML C++ Json Example"

    Connections{
        target: ProjectSettings
        onXChanged : xText.text = ProjectSettings.getX();
        onYChanged : yText.text = ProjectSettings.getY();
        onZChanged : zText.text = ProjectSettings.getZ();
    }

    Column{
        spacing: 5

        Text{
            text: "Proje Settings"
        }

        Row{
            spacing: 5

            Text{
                text: "X:"
            }

            TextField{
                Keys.onEnterPressed: {
                    ProjectSettings.setX(text);
                }
            }
        }

        Row{
            spacing: 5

            Text{
                text: "Y:"
            }

            TextField{
                Keys.onEnterPressed: {
                    ProjectSettings.setY(text);
                }
            }
        }

        Row{
            spacing: 5

            Text{
                text: "Z:"
            }

            TextField{
                Keys.onEnterPressed: {
                    ProjectSettings.setZ(text);
                }
            }
        }

        Row{
            spacing: 5

            TextField{
                placeholderText: "Enter Json File Name"
                Keys.onEnterPressed: {
                    ProjectSettings.setName(text);
                }
            }

            Button{
                text: "Save Project"
                onClicked: ProjectSettings.save();
            }

            Button{
                text: "Load Project"
                onClicked: ProjectSettings.load();

            }
        }

        Column{
            Text{
                text: "Saved Projet Settings"
            }

            Row{
                Text {
                    text: "X: "
                }

                Text {
                    id : xText;
                    text: "-"
                }
            }

            Row{
                Text {
                    text: "Y: "
                }

                Text {
                    id : yText;
                    text: "-"
                }
            }

            Row{
                Text {
                    text: "Z: "
                }

                Text {
                    id : zText;
                    text: "-"
                }
            }
        }
    }
}
