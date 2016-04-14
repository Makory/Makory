#Makory
Make와 Memory의 합성어로 사진 속의 기억들을 영상으로 다시 만드는 프로그램입니다.

사용자가 원하는 템플릿을 고르고 이미지와 텍스트를 입력하면 그에 맞게 동영상을 만들어주는 프로그램

기본 템플릿은 각각 테마를 가지고 있으며 기본 색상에서 색상을 조정할 수 있음

프로그램이 이미지와 텍스트의 개수를 제한하지 말고 사용자가 원하는 개수만큼 채워져야 함

만들어진 동영상은 실제 동영상 파일로 추출 가능해야 함



You have to setup OpenGL, OpenCV.

You will need to add a file in 'Makory' folder, such as:

opencv_world300.dll

opencv_world300d.dll

These files are too large, it can not be uploaded.





이미지를 불러오고 이미지나 템플릿을 선택하면 타임라인에 순서대로 들어가며 타임라인에 있는 템플릿을 선택하면 화면에 OpenGL로 뿌려주는 것까지 완료.

1 이미지도 화면에 같이 뿌려줘야 한다
2 템플릿을 제대로 만들어 추가하고
3 애니메이션 기능이 들어가야하고
4 템플릿별로 편집 기능을 추가해야함
5 타임라인에서 순서를 바꿀 수 있어야함
6 텍스트 매핑 구현
7 최종 동영상 추출
