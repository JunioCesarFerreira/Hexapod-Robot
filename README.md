# Hexapod-Robot

🌍 *[**Português**](README.md) ∙ [English](README_en.md)*

## Descrição
Neste repositório estão alguns dados de um projeto de robô hexapod que venho implementando há algum tempo. O projeto original foi iniciado em 2016, quando desenhei e preparei a estrutura mecânica. Naquela época, minha intenção era utilizar o MCU PIC18F4550 como controlador. Na versão atual, desenvolvida em 2023, estou utilizando o ESP32-S2. Esta é uma versão a ser completada. Pretendo ir adicionando mais detalhes do projeto (circuito eletrônico e layouts), bem como continuar evoluindo o código atual no ESP32-S2.

## Tecnologia e Componentes
- **Microcontrolador Atual**: ESP32-S2, escolhido por seu desempenho superior e recursos de IoT.
- **PlatformIO com VS Code**: O projeto do firmware foi implementando utilizando o framework do Arduino no PlatformIO no VS Code.

## Estrutura do Repositório
- `HexapodRobot`: Diretório principal do projeto, contendo código-fonte, bibliotecas e testes para o ESP32-S2.
- `MechanicProject`: Desenhos e modelos mecânicos do robô, incluindo arquivos de CAD compatíveis com Softwares como SolidWorks.

## Instalação e Configuração
Para contribuir ou testar o projeto, siga estas etapas:
1. Instale o PlatformIO IDE ou integre-o ao Visual Studio Code.
2. Clone o repositório e navegue até o diretório `HexapodRobot`.
3. Siga as instruções no `platformio.ini` para configurar seu ambiente de desenvolvimento.

## Uso
Instruções para montar o robô e programá-lo com o código fornecido:
1. Monte o hardware do robô hexápode conforme os designs em `MechanicProject`.
2. Carregue o código do diretório `HexapodRobot` no ESP32-S2.
3. Siga as instruções detalhadas no código para controle e operações do robô.

## Protótipo

![prototype](./resource/prototype.gif)

## Contribuição
Suas contribuições são importantes para o desenvolvimento contínuo do projeto. Para contribuir:
1. Faça um fork do repositório.
2. Crie um branch para sua feature.
3. Envie um pull request detalhando suas mudanças.

## Licença
Este projeto é distribuído sob a Licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

