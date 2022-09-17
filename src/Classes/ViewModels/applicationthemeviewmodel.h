/*
    AniLibria - desktop client for the website anilibria.tv
    Copyright (C) 2021 Roman Vladimirov

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef APPLICATIONTHEMEVIEWMODEL_H
#define APPLICATIONTHEMEVIEWMODEL_H

#include <QObject>
#include <QMap>

class ApplicationThemeViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString selectedTheme READ selectedTheme WRITE setSelectedTheme NOTIFY selectedThemeChanged)
    Q_PROPERTY(QString plainTextColor READ plainTextColor NOTIFY plainTextColorChanged)
    Q_PROPERTY(QString headerTextColor READ headerTextColor NOTIFY headerTextColorChanged)
    Q_PROPERTY(QString linkTextColor READ linkTextColor NOTIFY linkTextColorChanged)
    Q_PROPERTY(QString pageVerticalPanel READ pageVerticalPanel NOTIFY pageVerticalPanelChanged)
    Q_PROPERTY(QString pageBackground READ pageBackground NOTIFY pageBackgroundChanged)
    Q_PROPERTY(QString pageUpperPanel READ pageUpperPanel NOTIFY pageUpperPanelChanged)
    Q_PROPERTY(QString panelBackground READ panelBackground NOTIFY panelBackgroundChanged)
    Q_PROPERTY(QString panelBackgroundShadow READ panelBackgroundShadow NOTIFY panelBackgroundShadowChanged)
    Q_PROPERTY(QString roundedButtonBackground READ roundedButtonBackground NOTIFY roundedButtonBackgroundChanged)
    Q_PROPERTY(QString roundedButtonBackgroundDisabled READ roundedButtonBackgroundDisabled NOTIFY roundedButtonBackgroundDisabledChanged)
    Q_PROPERTY(QString roundedButtonForeground READ roundedButtonForeground NOTIFY roundedButtonForegroundChanged)
    Q_PROPERTY(QString roundedButtonHovered READ roundedButtonHovered NOTIFY roundedButtonHoveredChanged)
    Q_PROPERTY(QString drawerGradiendStep0 READ drawerGradiendStep0 NOTIFY drawerGradiendStep0Changed)
    Q_PROPERTY(QString drawerGradiendStep1 READ drawerGradiendStep1 NOTIFY drawerGradiendStep1Changed)
    Q_PROPERTY(QString drawerGradiendStep2 READ drawerGradiendStep2 NOTIFY drawerGradiendStep2Changed)
    Q_PROPERTY(QString drawerGradiendStep3 READ drawerGradiendStep3 NOTIFY drawerGradiendStep3Changed)
    Q_PROPERTY(QString drawerGradiendStep4 READ drawerGradiendStep4 NOTIFY drawerGradiendStep4Changed)
    Q_PROPERTY(QString filterIconButtonColor READ filterIconButtonColor NOTIFY filterIconButtonColorChanged)
    Q_PROPERTY(QString filterIconButtonGreenColor READ filterIconButtonGreenColor NOTIFY filterIconButtonGreenColorChanged)
    Q_PROPERTY(QString filterIconButtonHoverColor READ filterIconButtonHoverColor NOTIFY filterIconButtonHoverColorChanged)
    Q_PROPERTY(QString selectedItem READ selectedItem NOTIFY selectedItemChanged)
    Q_PROPERTY(QString selectedFavorite READ selectedFavorite NOTIFY selectedFavoriteChanged)
    Q_PROPERTY(QString playerControlBackground READ playerControlBackground NOTIFY playerControlBackgroundChanged)
    Q_PROPERTY(QString notificationCenterBackground READ notificationCenterBackground NOTIFY notificationCenterBackgroundChanged)
    Q_PROPERTY(QString notificationCenterPanelBackground READ notificationCenterPanelBackground NOTIFY notificationCenterPanelBackgroundChanged)
    Q_PROPERTY(QString notificationCenterItemBackground READ notificationCenterItemBackground NOTIFY notificationCenterItemBackgroundChanged)
    Q_PROPERTY(QString playlistSelectedBackground READ playlistSelectedBackground NOTIFY playlistSelectedBackgroundChanged)
    Q_PROPERTY(QString playlistBackground READ playlistBackground NOTIFY playlistBackgroundChanged)
    Q_PROPERTY(QString playlistSelectedText READ playlistSelectedText NOTIFY playlistSelectedTextChanged)
    Q_PROPERTY(QString playlistText READ playlistText NOTIFY playlistTextChanged)

private:
    QString m_selectedTheme { "" };
    QMap<QString, QMap<QString, QString>> m_themes { QMap<QString, QMap<QString, QString>>() };

    const QString plainTextColorField = "plainTextColor";
    const QString headerTextColorField = "headerTextColor";
    const QString linkTextColorField = "linkTextColor";
    const QString pageVerticalPanelField = "pageVerticalPanel";
    const QString pageBackgroundField = "pageBackground";
    const QString pageUpperPanelField = "pageUpperPanel";
    const QString panelBackgroundField = "panelBackground";
    const QString panelBackgroundShadowField = "panelBackgroundShadow";
    const QString roundedButtonBackgroundField = "roundedButtonBackground";
    const QString roundedButtonBackgroundDisabledField = "roundedButtonBackgroundDisabled";
    const QString roundedButtonForegroundField = "roundedButtonForeground";
    const QString roundedButtonHoveredField = "roundedButtonHovered";
    const QString drawerGradiendStep0Field = "drawerGradiendStep0";
    const QString drawerGradiendStep1Field = "drawerGradiendStep1";
    const QString drawerGradiendStep2Field = "drawerGradiendStep2";
    const QString drawerGradiendStep3Field = "drawerGradiendStep3";
    const QString drawerGradiendStep4Field = "drawerGradiendStep4";
    const QString filterIconButtonColorField = "filterIconButtonColor";
    const QString filterIconButtonGreenColorField = "filterIconButtonGreenColor";
    const QString filterIconButtonHoverColorField = "filterIconButtonHoverColor";
    const QString selectedItemField = "selectedItem";
    const QString selectedFavoriteField = "selectedFavorite";
    const QString playerControlBackgroundField = "playerControlBackground";
    const QString notificationCenterBackgroundField = "notificationCenterBackground";
    const QString notificationCenterPanelBackgroundField = "notificationCenterPanelBackground";
    const QString notificationCenterItemBackgroundField = "notificationCenterItemBackground";
    const QString playlistSelectedBackgroundField = "playlistSelectedBackground";
    const QString playlistBackgroundField = "playlistBackground";
    const QString playlistSelectedTextField = "playlistSelectedText";
    const QString playlistTextField = "playlistText";

public:
    explicit ApplicationThemeViewModel(QObject *parent = nullptr);

    QString selectedTheme() const noexcept { return m_selectedTheme; }
    void setSelectedTheme(const QString& selectedTheme) noexcept;

    QString plainTextColor() const noexcept { return m_themes[m_selectedTheme][plainTextColorField]; }
    QString headerTextColor() const noexcept { return m_themes[m_selectedTheme][headerTextColorField]; }
    QString linkTextColor() const noexcept { return m_themes[m_selectedTheme][linkTextColorField]; }
    QString pageVerticalPanel() const noexcept { return m_themes[m_selectedTheme][pageVerticalPanelField]; }
    QString pageBackground() const noexcept { return m_themes[m_selectedTheme][pageBackgroundField]; }
    QString pageUpperPanel() const noexcept { return m_themes[m_selectedTheme][pageUpperPanelField]; }
    QString panelBackground() const noexcept { return m_themes[m_selectedTheme][panelBackgroundField]; }
    QString panelBackgroundShadow() const noexcept { return m_themes[m_selectedTheme][panelBackgroundShadowField]; }
    QString roundedButtonBackground() const noexcept { return m_themes[m_selectedTheme][roundedButtonBackgroundField]; }
    QString roundedButtonBackgroundDisabled() const noexcept { return m_themes[m_selectedTheme][roundedButtonBackgroundDisabledField]; }
    QString roundedButtonForeground() const noexcept { return m_themes[m_selectedTheme][roundedButtonForegroundField]; }
    QString roundedButtonHovered() const noexcept { return m_themes[m_selectedTheme][roundedButtonHoveredField]; }
    QString drawerGradiendStep0() const noexcept { return m_themes[m_selectedTheme][drawerGradiendStep0Field]; }
    QString drawerGradiendStep1() const noexcept { return m_themes[m_selectedTheme][drawerGradiendStep1Field]; }
    QString drawerGradiendStep2() const noexcept { return m_themes[m_selectedTheme][drawerGradiendStep2Field]; }
    QString drawerGradiendStep3() const noexcept { return m_themes[m_selectedTheme][drawerGradiendStep3Field]; }
    QString drawerGradiendStep4() const noexcept { return m_themes[m_selectedTheme][drawerGradiendStep4Field]; }
    QString filterIconButtonColor() const noexcept { return m_themes[m_selectedTheme][filterIconButtonColorField]; }
    QString filterIconButtonGreenColor() const noexcept { return m_themes[m_selectedTheme][filterIconButtonGreenColorField]; }
    QString filterIconButtonHoverColor() const noexcept { return m_themes[m_selectedTheme][filterIconButtonHoverColorField]; }
    QString selectedItem() const noexcept { return m_themes[m_selectedTheme][selectedItemField]; }
    QString selectedFavorite() const noexcept { return m_themes[m_selectedTheme][selectedFavoriteField]; }
    QString playerControlBackground() const noexcept { return m_themes[m_selectedTheme][playerControlBackgroundField]; }
    QString notificationCenterBackground() const noexcept { return m_themes[m_selectedTheme][notificationCenterBackgroundField]; }
    QString notificationCenterPanelBackground() const noexcept { return m_themes[m_selectedTheme][notificationCenterPanelBackgroundField]; }
    QString notificationCenterItemBackground() const noexcept { return m_themes[m_selectedTheme][notificationCenterItemBackgroundField]; }
    QString playlistSelectedBackground() const noexcept { return m_themes[m_selectedTheme][playlistSelectedBackgroundField]; }
    QString playlistBackground() const noexcept { return m_themes[m_selectedTheme][playlistBackgroundField]; }
    QString playlistSelectedText() const noexcept { return m_themes[m_selectedTheme][playlistSelectedTextField]; }
    QString playlistText() const noexcept { return m_themes[m_selectedTheme][playlistTextField]; }

signals:
    void selectedThemeChanged();
    void plainTextColorChanged();
    void headerTextColorChanged();
    void linkTextColorChanged();
    void pageVerticalPanelChanged();
    void pageBackgroundChanged();
    void pageUpperPanelChanged();
    void panelBackgroundChanged();
    void panelBackgroundShadowChanged();
    void roundedButtonBackgroundChanged();
    void roundedButtonBackgroundDisabledChanged();
    void roundedButtonForegroundChanged();
    void roundedButtonHoveredChanged();
    void drawerGradiendStep0Changed();
    void drawerGradiendStep1Changed();
    void drawerGradiendStep2Changed();
    void drawerGradiendStep3Changed();
    void drawerGradiendStep4Changed();
    void filterIconButtonColorChanged();
    void filterIconButtonGreenColorChanged();
    void filterIconButtonHoverColorChanged();
    void selectedItemChanged();
    void selectedFavoriteChanged();
    void playerControlBackgroundChanged();
    void notificationCenterBackgroundChanged();
    void notificationCenterPanelBackgroundChanged();
    void notificationCenterItemBackgroundChanged();
    void playlistSelectedBackgroundChanged();
    void playlistBackgroundChanged();
    void playlistSelectedTextChanged();
    void playlistTextChanged();

};

#endif // APPLICATIONTHEMEVIEWMODEL_H