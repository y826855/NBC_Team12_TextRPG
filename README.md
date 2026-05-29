# NBC_Team12_TextRPG
내일배움 캠프에서 진행하는 TEXT RPG 제작

## 🗺️ 노션
https://www.notion.so/teamsparta/12-3672dc3ef5148068a6c5c01bba994dcb?v=3672dc3ef514805ea946000c5316fdd5&source=copy_link

## 유튜브 링크
[https://miro.com/app/board/uXjVLi9zwcE=/](https://www.youtube.com/watch?v=LIntOO1z5uE)

## 📝 기획 및 설계구조

---
## 🎯 프로젝트 소개: Text-Console RPG
이 과제의 본질은 단순히 게임을 완성하는 것이 아니라, 객체지향 원칙(SOLID)을 적용해 나중에 몬스터나 아이템을 쉽게 추가할 수 있는 견고한 게임 시스템을 구축하는 것입니다.

### 👤 플레이어 캐릭터 생성
이름 설정 가능 / 상태 확인 가능
초기 스탯: Lv1 / 체력 200 / 공격력 30 / 경험치 0
레벨업 필요 경험치: 100
### 👾 몬스터
이름 / 체력 / 공격력 보유
랜덤 스탯:
❤️ 체력 = (Lv × 20) ~ (Lv × 30)
⚔️ 공격력 = (Lv × 5) ~ (Lv × 10)
### ⚔️ 전투 시스템
랜덤 몬스터 등장 / 턴제 전투 / 자동 행동
전투 시작 조건: 캐릭터 생성 직후 / 상점 스킵 후 / 상점 이용 후
🎁 승리 보상: ⭐ 경험치 50 / 💰 골드 10~20 랜덤 / 🎲 아이템 30% 확률 획득
경험치 100 이상 시 레벨업
### 📈 레벨업
❤️ 체력 증가 = Lv × 20
⚔️ 공격력 증가 = Lv × 5
체력 최대치 회복 / 최대 레벨 10
### 🧪 아이템
🧴 포션 = 체력 +50
⚔️ 공격력 증가 = 공격력 +10 (현재 전투만 적용)
사용 즉시 삭제 및 효과 적용
전투 중 랜덤 사용 가능
### 📜 게임 로그
공격 / 피해 / 아이템 사용 / 골드 획득 출력
몬스터 처치 기록 확인 가능
### 👑 보스전
Lv10 달성 시 등장
💬 “이제 일반 몬스터는 상대도 안 된다!”
👹 보스 스탯 = 기존 몬스터의 1.5배 범위 랜덤
클리어 시 엔딩 진행
### 🏪 상점 시스템
전투 후 입장 여부 선택
🛒 구매: 골드 사용 / 인벤토리 즉시 추가 / 가격 고정
💸 판매: 아이템 제거 / 골드 획득 / 판매 가격 = 원가의 60%
📦 아이템 목록 자유 제작

## 🎮 조작법 (Controls)

본 게임은 **콘솔 창 입력**을 통해 진행됩니다.

기본 조작 시스템

*숫자 선택 (`1`, `2`, `3` 등) + `Enter` : 메뉴 이동, 행동 선택, 아이템 구매 및 장착

*`0` + `Enter` : 이전 화면으로 돌아가기 또는 뒤로가기

## Class UML

클래스의 역활과 연결 구조를 나타내는 UML입니다
---
<img width="7126" height="6009" alt="EItem Ecosystem and Battle-2026-05-28-070251" src="https://github.com/user-attachments/assets/d6362d34-8ef0-4efb-b81b-2907595987d2" />

## Flow Chart
알고리즘의 조건 분기점을 나타내는 Flow Chart 입니다
---
<img width="3026" height="6327" alt="EItem Ecosystem and Battle-2026-05-28-061602" src="https://github.com/user-attachments/assets/1b9ec665-5652-4bee-b009-f3f5d34fb631" />


## Sequence Diagram
시간 흐름에 따라 구조들이 어떻게 호출되는 지 보여주는 Sequence Diagram 입니다
---
<img width="4119" height="8192" alt="Lobby Interaction Pipeline-2026-05-27-081627" src="https://github.com/user-attachments/assets/43572cfc-fa05-4369-a265-97853d17eb40" />

