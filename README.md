# factory_u2f_crack

## 常用命令

创建App

```sh
ufbt create APPID=<app_id>
```


# uFBT - 微型 Flipper 构建工具


**uFBT 有一个[官方 GitHub Action](https://github.com/marketplace/actions/build-flipper-application-package-fap)。借助它，您可以使用 GitHub 工作流自动化构建和发布您的应用程序。**

## 安装

- **Linux 和 macOS**: `python3 -m pip install --upgrade ufbt`
- **Windows**: `py -m pip install --upgrade ufbt`

## 使用方法

### 构建并运行您的应用程序

在您的应用程序的根目录下运行 `ufbt`（该目录应包含 `application.fam` 文件）。它将构建您的应用程序，并将生成的二进制文件放在 `dist` 子目录中。

您可以使用 `ufbt launch` 上传并启动通过 USB 连接的 Flipper 上的应用程序。

要查看其他可用命令和选项，请运行 `ufbt -h`。

### 调试

为了调试您的应用程序，您需要运行与当前 SDK 版本一起分发的固件。您可以使用 `ufbt flash`（使用支持的 SWD 探针）或 `ufbt flash_usb`（通过 USB）将其刷写到您的 Flipper。

有关其他刷写和调试选项，请参见 `ufbt -h`。

### VSCode 集成

uFBT 提供了一个 VSCode 配置，允许您直接在 IDE 中构建和调试应用程序。要部署它，请在应用程序的根目录下运行 `ufbt vscode_dist`。然后，您可以在 VSCode 中打开项目（`文件`-`打开文件夹...`）并使用提供的启动（`ctrl+shift+b`）和调试（`ctrl+shift+d`）配置。

### 应用程序模板

uFBT 可以为您的应用程序创建模板。为此，请在您希望创建应用程序的目录下运行 `ufbt create APPID=<app_id>`。它将创建一个应用程序清单及其主源文件。然后，您可以使用上述说明来构建和调试您的应用程序。

应用程序清单的详细信息可以在 [FBT 文档](https://github.com/flipperdevices/flipperzero-firmware/blob/dev/documentation/AppManifests.md)中找到。

### 其他功能

- `ufbt cli` 启动与设备的 CLI 会话；
- `ufbt lint` 和 `ufbt format` 对应用程序的源代码运行 clang-format；
- 您可以暂时将工具链二进制文件（编译器、linter、OpenOCD 等）添加到 PATH 中。有关更多信息，请参见 `ufbt --help`。

## 管理 SDK

要更新 SDK，请运行 `ufbt update`。这将从之前使用的源下载并安装所有必需的 SDK 组件。

- 要切换到不同 **发布渠道** 的 SDK，请运行 `ufbt update --channel=[dev|rc|release]`。
    - uFBT 还支持第三方更新索引器，遵循与[官方固件](https://github.com/flipperdevices/flipperzero-firmware)相同的架构。要使用它们，请运行 `ufbt update --index-url=<url>`，其中 `<url>` 是索引文件的 URL，例如 `https://update.flipperzero.one/firmware/directory.json`。
- 要使用某个 **特定发布版本** 或尚未合并的 **分支** 中的 SDK，请运行 `ufbt update --branch=0.81.1` 或 `ufbt update --branch=owner/my-awesome-feature`。
    - 您还可以使用其他存储库中的分支（如果可以从索引目录中获取构建工件），方法是指定 `--index-url=<url>`。
- uFBT 还可以从任何 **固定 URL** 下载并更新 SDK。为此，请运行 `ufbt update --url=<url>`。
- 要使用 SDK 的 **本地副本**，请运行 `ufbt update --local=<path>`。这将使用 `<path>` 中的 SDK，而不是下载它。对于测试本地构建的 SDK 非常有用。

### 全局和按项目管理 SDK

默认情况下，uFBT 将其状态（SDK 和工具链）存储在主目录下的 `.ufbt` 子文件夹中。您可以通过设置 `UFBT_HOME` 环境变量来覆盖此位置。

uFBT 还支持 dotenv (`.env`) 文件，该文件包含当前目录中项目的环境变量覆盖。最常见的用途是覆盖默认状态目录为本地目录，以便您的项目可以使用特定版本和/或硬件目标的 SDK。

您可以通过运行 `ufbt dotenv_create` 为当前目录启用 dotenv 模式。这将在当前目录中创建 `.env` 文件，并使用默认值，将 SDK 状态链接到当前目录下的 `.ufbt` 子文件夹，并在您的主目录中为工具链创建 `.ufbt/toolchain` 的符号链接。然后，您可以编辑 `.env` 文件以进一步自定义环境。

您还可以在创建 `.env` 文件时指定其他选项。有关更多信息，请参见 `ufbt dotenv_create --help`。

### ufbt-bootstrap

SDK 的更新由 uFBT 组件 _bootstrap_ 处理。它有一个专用的入口点 `ufbt-bootstrap`，其中包含某些场景下可能有用的附加选项。运行 `ufbt-bootstrap --help` 查看这些选项。

## 故障排除

如果出现问题并且 uFBT 状态损坏，您可以通过运行 `ufbt clean` 来重置它。如果这不起作用，您可以尝试手动从主文件夹中删除 `.ufbt` 子文件夹。

`ufbt-bootstrap` 和 SDK 相关的 `ufbt` 子命令接受 `--verbose` 选项，该选项将打印附加的调试信息。