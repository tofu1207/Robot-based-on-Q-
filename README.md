# Robot-based-on-Q-
框架: https://github.com/CoolQ/cqsdk-vc/

程序说明:
VC++    开发框架:https://github.com/CoolQ/cqsdk-vc/
这个机器人主要是针对聊天开发的(里面现在没有聊天, 只有个可以直接上代码的框架), 机器人通过ShallowBird.ini文件进行初始化, 保存了名字先别生日爱好喜欢的东西口头禅梦想等等信息, 交流方(与她对话的人)的信息将会自动获取到群聊, 私聊消息中的每个人信息, 保存了qq名字性别生日好感度(机器人对此人)文件保存在c盘下的Person.ini.
自定义聊天只需要在RobotAsync.cpp的处理消息队列中进行编写
建议在PrivateMsg, GroupMsg中进行私聊信息和群聊信息的处理, 里面有示例展示
如果需要正则的判断(或是自己要编写正则表达式), 建议在regexFun中进行编写, 同样也有示例

关于以后的优化:
1. 改用新框架
2. 结合python编写机器人的深度学习算法
人格化
点 (故事)
姓名, 年龄, 爱好, 性格, 运动, 梦想, 爱人, 口头禅

线 (记忆)
经历导致的特定性格爱好等

面 (社交关系网络)
过分析对话确立社交关系网络

生命化 (个性体现)
点线面
结合点线面的形象, 让robot在长久的开发中逐渐成长
交互能力: 规划, 推理, 联想, 情感, 学习等

聊天模块

目前完成点, 记忆方面和社交网络在今后看情况, 看心情开发